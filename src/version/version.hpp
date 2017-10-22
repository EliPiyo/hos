/**
 * Hyper Operating System - Version info
 * Shinohara Heavy Industry 1999
 */
#ifndef __VERSION_HPP__
#define __VERSION_HPP__

#include <chrono>
#include <cstdint>

namespace version {
class version {
public:
    version(uint32_t const major_version, uint32_t const minor_version);
    virtual ~version();

    void show(std::chrono::milliseconds char_delay);

private:
    uint32_t const major_version_;
    uint32_t const minor_version_;
};
}
#endif // __VERSION_HPP__