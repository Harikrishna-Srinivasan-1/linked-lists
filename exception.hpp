#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <stdexcept>
#include <sstream>

class Exception: public std::runtime_error
{
    private:
        std::string err_msg;
    public:
        Exception(const std::string &msg, const char *file, int line, const char *func);
        virtual ~Exception() noexcept = default;
        
        const char* what() const noexcept override;
};

class IndexError: public Exception
{
    public:
        IndexError(const std::string &msg, const char *file, int line, const char *func);
        ~IndexError() noexcept = default;
};

class ValueError: public Exception
{
    public:
        ValueError(const std::string &msg, const char *file, int line, const char *func);
        ~ValueError() noexcept = default;
};

class TypeError: public Exception
{
    public:
        TypeError(const std::string &msg, const char *file, int line, const char *func);
        ~TypeError() noexcept = default;
};

#define INDEX_ERROR(msg) IndexError(msg, __FILE__, __LINE__, __func__)
#define VALUE_ERROR(msg) ValueError(msg, __FILE__, __LINE__, __func__)
#define TYPE_ERROR(msg) TypeError(msg, __FILE__, __LINE__, __func__)

#include "./exception.tpp"

#endif
