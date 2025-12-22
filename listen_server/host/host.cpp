#include <iostream>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "../common/protocol.h"

#define PORT 5000
#define BUFFER_SIZE 1024

std::unordered_map<int, int> clients; // client_id -> socket
std::mutex clients_mutex;
int client_id_counter = 1;

void broadcast(const std::string& msg) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (auto& [id, sock] : clients) {
        send(sock, msg.c_str(), msg.size(), 0);
    }
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int client_id;

    // Receive JOIN
    int bytes = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (bytes <= 0) return;

    std::string join_msg(buffer, bytes);
    auto parts = split(join_msg, '|');
    std::string username = parts.size() >= 3 ? parts[2] : "Unknown";

    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        client_id = client_id_counter++;
        clients[client_id] = client_sock;
    }

    std::string welcome = "JOIN|" + std::to_string(client_id) + "|Welcome\n";
    send(client_sock, welcome.c_str(), welcome.size(), 0);

    broadcast("CHAT|0|" + username + " joined the chat\n");

    // Message loop
    while (true) {
        bytes = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) break;

        std::string msg(buffer, bytes);
        broadcast(msg);
        std::cout << msg;
    }

    // Cleanup
    close(client_sock);
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients.erase(client_id);
    }

    broadcast("CHAT|0|A client disconnected\n");
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, 5);

    std::cout << "[HOST] Listening on port " << PORT << std::endl;

    // Host input thread (host acts as client)
    std::thread host_input([]() {
        while (true) {
            std::string msg;
            getline(std::cin, msg);
            broadcast("CHAT|0|HOST: " + msg + "\n");
        }
    });

    while (true) {
        int client_sock = accept(server_sock, nullptr, nullptr);
        std::thread(handle_client, client_sock).detach();
    }

    host_input.join();
    close(server_sock);
    return 0;
}
