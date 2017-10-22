/**
 * Hyper Operating System - Executioner
 * Shinohara Heavy Industry 1999
 */
#ifndef __EXECUTIONER_HPP__
#define __EXECUTIONER_HPP__

#include <chrono>

namespace executioner {
class executioner {
public:
    executioner();
    virtual ~executioner();

    void execution(std::chrono::milliseconds const char_delay);

private:
    void genesis(std::chrono::milliseconds const char_delay, size_t ws_col,
                 size_t ws_row);
    void collapse(size_t ws_col, size_t ws_row);
};
}
#endif // __EXECUTIONER_HPP__