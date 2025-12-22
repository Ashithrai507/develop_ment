#include <iostream>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

void receive_loop(int sock) {
    char buffer[BUFFER_SIZE];
    while (true) {
        int bytes = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) break;
        std::cout << std::string(buffer, bytes);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./client <host_ip>\n";
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    connect(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    std::string name;
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::string join = "JOIN|0|" + name + "\n";
    send(sock, join.c_str(), join.size(), 0);

    std::thread recv_thread(receive_loop, sock);

    while (true) {
        std::string msg;
        getline(std::cin, msg);
        std::string chat = "CHAT|0|" + msg + "\n";
        send(sock, chat.c_str(), chat.size(), 0);
    }

    recv_thread.join();
    close(sock);
    return 0;
}
