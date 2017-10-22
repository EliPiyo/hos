/**
 * Hyper Operating System - Login sequence
 * Shinohara Heavy Industry 1999
 */

#include "login_sequence.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include "../util/slow_console.hpp"

namespace login_sequence {
const static std::string COLOR_PREFIX = "\e[37m";
const static std::string COLOR_POSTFIX = "\e[m";
constexpr uint32_t DELAY_MS = 1000;

login_sequence::login_sequence(std::string const shadow_file,
                               std::chrono::milliseconds const char_delay)
  : shadow_file_(shadow_file), char_delay_(char_delay) {}

login_sequence::~login_sequence() {}

bool login_sequence::login(std::string const user_name) {
    std::cout << COLOR_PREFIX;

    util::slow_console console(char_delay_);
    console.print("enter " + user_name + " password");

    auto delay = std::chrono::milliseconds(DELAY_MS);
    std::this_thread::sleep_for(delay);

    std::cout << std::endl;

    console.print("pass: ");

    std::string passwd;
    std::cin >> passwd;

    std::cout << COLOR_POSTFIX;

    size_t input_hash = std::hash<std::string>()(passwd);
    size_t registered_hash = get_hash_from_shadow(user_name);

    return input_hash == registered_hash;
}

size_t login_sequence::get_hash_from_shadow(std::string const user_name) {
    try {
        std::fstream file(shadow_file_, std::ios_base::in);
        std::string buf;
        while (file && std::getline(file, buf)) {
            auto divider = buf.find(":");
            auto name = buf.substr(0, divider);
            size_t hash =
              std::stoull(buf.substr(divider + 1, buf.size() - (divider + 1)));
            if (name == user_name) {
                return hash;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "no shadow file." << std::endl;
    }
    return 0;
}
}
