#ifndef EXCPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>


class Exception: virtual public std::exception 
{
    protected:
        std::string what_arg;
    public:
        Exception();
        virtual const char *what();
        virtual ~Exception();
};

class IndexError: public Exception
{
    public:
        explicit IndexError(std::string what_arg);
        ~IndexError();
};

class ValueError: public Exception
{
    public:
        explicit ValueError(std::string what_arg);
        ~ValueError();
};

class TypeError: public Exception
{
    public:
       explicit TypeError(std::string what_arg);
       ~TypeError();
};

#endif
