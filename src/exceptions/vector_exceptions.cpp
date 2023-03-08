#include "TLA/exceptions.h"
#include <exception>
#include <string>

IndexOutsideTheVector::IndexOutsideTheVector(const std::string& message) : message_(message) {}
const char* IndexOutsideTheVector::what() const noexcept {
    return message_.c_str();
}