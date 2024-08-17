#include "exception.h"


// TODO: Improve Exception throwing mechanism
Exception::Exception() {}

Exception::~Exception() {}

const char *Exception::what()
{
    return (this->what_arg).c_str();
}

IndexError::IndexError(std::string what_arg)
{
    this->what_arg = what_arg;
}

IndexError::~IndexError() {}

ValueError::ValueError(std::string what_arg)
{
    this->what_arg = what_arg;
}

ValueError::~ValueError() {}

TypeError::TypeError(std::string what_arg)
{
    this->what_arg = what_arg;
}

TypeError::~TypeError() {}

