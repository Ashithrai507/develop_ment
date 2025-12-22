// common/protocol.h
#pragma once
#include <string>
#include <sstream>
#include <vector>

enum MessageType {
    JOIN,
    CHAT,
    LEAVE,
    UNKNOWN
};

inline MessageType parseType(const std::string& type) {
    if (type == "JOIN") return JOIN;
    if (type == "CHAT") return CHAT;
    if (type == "LEAVE") return LEAVE;
    return UNKNOWN;
}

// Split helper
inline std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
