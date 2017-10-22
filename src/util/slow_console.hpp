/**
 * Hyper Operating System - Slow console
 * Shinohara Heavy Industry 1999
 */
#ifndef __SLOW_CONSOLE_HPP__
#define __SLOW_CONSOLE_HPP__

#include <chrono>
#include <string>

namespace util {
class slow_console {
public:
    slow_console(std::chrono::microseconds const char_delay);
    virtual ~slow_console();

    void print(std::string const str);

private:
    std::chrono::microseconds const char_delay_;
};
}

#endif // __SLOW_CONSOLE_HPP__