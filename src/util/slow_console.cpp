/**
 * Hyper Operating System - Slow console
 * Shinohara Heavy Industry 1999
 */

#include "slow_console.hpp"

#include <iostream>
#include <thread>

namespace util {
slow_console::slow_console(std::chrono::microseconds const char_delay)
  : char_delay_(char_delay) {}

slow_console::~slow_console() {}

void slow_console::print(std::string str) {
    for (auto ch : str) {
        std::cout << ch;
        std::cout.flush();
        std::this_thread::sleep_for(char_delay_);
    }
}
}