#ifndef _VECTOR_EXCEPTIONS_H_
#define _VECTOR_EXCEPTIONS_H_ 1

#include <string>
#include <exception>

class IndexOutsideTheVector : public std::exception {
public:
    explicit IndexOutsideTheVector(const std::string& message) : message_(message) {}
    const char* what() const noexcept {
        return message_.c_str();
    }
private:
    std::string message_;
};

class EraseFromEmptyVector : public std::exception {
public:
    explicit EraseFromEmptyVector(const std::string& message) : message_(message) {}
    const char* what() const noexcept {
        return message_.c_str();
    }
private:
    std::string message_;
};

#endif // _VECTOR_EXCEPTIONS_H_