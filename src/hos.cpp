#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <memory>

#include "boot/boot.hpp"
#include "login_sequence/login_sequence.hpp"
#include "version/version.hpp"

constexpr uint32_t MAJOR_VERSION = 1;
constexpr uint32_t MINOR_VERSION = 0;
constexpr std::chrono::milliseconds CHAR_DELAY_MS =
  std::chrono::milliseconds(50);
const static std::string TERMINAL_CLEAR = "\033[2J\033[0;0H";

int main(int argc, char** argv) {
    std::cout << TERMINAL_CLEAR;

    auto ver = std::make_shared<version::version>(MAJOR_VERSION, MINOR_VERSION);
    ver->show(CHAR_DELAY_MS);

    std::cout << TERMINAL_CLEAR;

    auto boot = std::make_shared<boot::boot>();
    boot->attach("cd01", "/", std::chrono::milliseconds(3000), CHAR_DELAY_MS);

    auto login =
      std::make_shared<login_sequence::login_sequence>("shadow", CHAR_DELAY_MS);
    while (!login->login("author")) {
        std::cerr << "permission denied." << std::endl;
    }
}
