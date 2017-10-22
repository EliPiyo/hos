/**
 * Hyper Operating System - Boot sequence
 * Shinohara Heavy Industry 1999
 */

#include "boot.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <thread>

namespace boot {

const static std::string COLOR_PREFIX = "\e[37m";
const static std::string COLOR_POSTFIX = "\e[m";
constexpr uint32_t DELAY_MS = 3000;

boot::boot() {}

boot::~boot() {}

void boot::attach(std::string const device, std::string const mount_point,
                  std::chrono::milliseconds timeout,
                  std::chrono::milliseconds char_delay) {
    std::stringbuf buf;
    std::iostream stream(&buf);
    stream << COLOR_PREFIX;
    stream << "attach " << device << " " << mount_point;
    stream << COLOR_POSTFIX;
    auto str = buf.str();

    for (auto ch : str) {
        std::cout << ch;
        std::cout.flush();
        std::this_thread::sleep_for(char_delay);
    }

    auto delay = std::chrono::milliseconds(DELAY_MS);
    std::this_thread::sleep_for(delay);

    std::cout << std::endl;
}
}