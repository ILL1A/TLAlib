#ifndef _VECTOR_EXCEPTIONS_H_
#define _VECTOR_EXCEPTIONS_H_ 1

#include <string>
#include <exception>

class IndexOutsideTheVector : public std::exception {
public:
    explicit IndexOutsideTheVector(const std::string& message);
    const char* what() const noexcept override;
private:
    std::string message_;
};

class EraseFromEmptyVector : public std::exception {
public:
    explicit EraseFromEmptyVector(const std::string& message);
    const char* what() const noexcept override;
private:
    std::string message_;
};

#endif // _VECTOR_EXCEPTIONS_H_