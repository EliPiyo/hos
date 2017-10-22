/**
 * Hyper Operating System - Login sequence
 * Shinohara Heavy Industry 1999
 */
#ifndef __LOGIN_SEQUENCE_HPP__
#define __LOGIN_SEQUENCE_HPP__

#include <chrono>
#include <string>

namespace login_sequence {
class login_sequence {
public:
    login_sequence(std::string const shadow_file,
                   std::chrono::milliseconds const char_delay);
    virtual ~login_sequence();

    bool login(std::string const user_name);

private:
    size_t get_hash_from_shadow(std::string const user_name);
    std::string const shadow_file_;
    std::chrono::milliseconds const char_delay_;
};
}
#endif // __LOGIN_SEQUENCE_HPP__