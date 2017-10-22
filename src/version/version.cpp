/**
 * Hyper Operating System - Version info
 * Shinohara Heavy Industry 1999
 */

#include "version.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <thread>

namespace version {

const static std::string PROGRAM_NAME = "Hyper Operating System";
const static std::string VERSION_PREFIX = "Ver";
const static std::string TARGET_SYSTEM = "for ALL LABORS";
const static std::string COPYRIGHT_YEAR = "(c) 1999";
const static std::string COPYRIGHT_CORPORATION = "Shinohara Heavy Industry";
const static std::string COLOR_PREFIX = "\e[33m";
const static std::string COLOR_POSTFIX = "\e[m";
constexpr uint32_t DELAY_MS = 3000;

version::version(uint32_t const major_version, uint32_t const minor_version)
  : major_version_(major_version), minor_version_(minor_version) {}

version::~version() {}

void version::show(std::chrono::milliseconds char_delay) {
    std::stringbuf buf;
    std::iostream stream(&buf);
    stream << COLOR_PREFIX;
    stream << PROGRAM_NAME << std::endl;
    stream << VERSION_PREFIX << major_version_ << "," << minor_version_
           << std::endl;
    stream << TARGET_SYSTEM << std::endl;
    stream << COPYRIGHT_YEAR << std::endl;
    stream << COPYRIGHT_CORPORATION << std::endl;
    stream << COLOR_POSTFIX;
    auto str = buf.str();

    for (auto ch : str) {
        std::cout << ch;
        std::cout.flush();
        std::this_thread::sleep_for(char_delay);
    }

    auto delay = std::chrono::milliseconds(DELAY_MS);
    std::this_thread::sleep_for(delay);
}
}