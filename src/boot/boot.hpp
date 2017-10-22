/**
 * Hyper Operating System - Boot sequence
 * Shinohara Heavy Industry 1999
 */
#ifndef __BOOT_HPP__
#define __BOOT_HPP__

#include <chrono>
#include <string>

namespace boot {
class boot {
public:
    boot();
    virtual ~boot();

    void attach(std::string const device, std::string const mount_point,
                std::chrono::milliseconds timeout,
                std::chrono::milliseconds char_delay);

private:
};
}
#endif // __BOOT_HPP__