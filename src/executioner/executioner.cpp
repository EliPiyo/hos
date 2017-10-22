/**
 * Hyper Operating System - Executioner
 * Shinohara Heavy Industry 1999
 */

#include "executioner.hpp"

#include <sys/ioctl.h>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

#include "../util/slow_console.hpp"

namespace executioner {

const std::string GENESIS_1 = "Go to, let us go down, and there confound";
const std::string GENESIS_2 = "their language, that they may not understand";
const std::string GENESIS_3 = "one another's speech.";
const std::string BABEL = "BABEL ";
const static std::string WHITE_COLOR_PREFIX = "\e[37m";
const static std::string RED_COLOR_PREFIX = "\e[31m";
const static std::string COLOR_POSTFIX = "\e[m";
constexpr std::chrono::milliseconds GENESIS_DELAY_MS =
  std::chrono::milliseconds(4000);
constexpr std::chrono::milliseconds BLACKOUT_DELAY_MS =
  std::chrono::milliseconds(1000);
constexpr std::chrono::milliseconds LINE_DELAY_MS =
  std::chrono::milliseconds(500);

executioner::executioner() {}

executioner::~executioner() {}

void executioner::execution(std::chrono::milliseconds const char_delay) {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    genesis(char_delay, ws.ws_col, ws.ws_row);

    std::this_thread::sleep_for(GENESIS_DELAY_MS);

    std::cout << "\033[2J\033[" << ws.ws_row << ";0H";

    std::this_thread::sleep_for(BLACKOUT_DELAY_MS);

    collapse(ws.ws_col, ws.ws_row);
}

void executioner::genesis(std::chrono::milliseconds const char_delay,
                          size_t ws_col, size_t ws_row) {
    util::slow_console console(char_delay);

    size_t genesis_max_length =
      std::max(std::max(GENESIS_1.size(), GENESIS_2.size()), GENESIS_3.size());
    size_t x = (ws_col - genesis_max_length) / 2;
    size_t y = (ws_row - 3) / 2;

    std::cout << "\033[" << y + 0 << ";" << x << "H" << WHITE_COLOR_PREFIX;
    console.print(GENESIS_1);
    std::cout << "\033[" << y + 1 << ";" << x << "H";
    console.print(GENESIS_2);
    std::cout << "\033[" << y + 2 << ";" << x << "H";
    console.print(GENESIS_3);
    std::cout << COLOR_POSTFIX;
}

void executioner::collapse(size_t ws_col, size_t ws_row) {
    if (ws_col % BABEL.size() == 0) {
        ws_col -= 1;
    }
    std::string line;
    int next_index = 0;
    std::cerr << RED_COLOR_PREFIX;
    while (1) {
        line.clear();
        while (line.size() < ws_col) {
            int size = std::min(ws_col - line.size(), BABEL.size());
            line += BABEL.substr(next_index, size);
            if (size == BABEL.size()) {
                next_index = 0;
            } else {
                next_index = (next_index + size) % BABEL.size();
            }
        }
        std::cerr << line << std::endl;
        std::this_thread::sleep_for(LINE_DELAY_MS);
    }
}
}