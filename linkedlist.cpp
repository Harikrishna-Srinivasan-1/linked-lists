#include "linkedlist.h"


linkedlist<A>::linkedlist():
head(NULL), length(0) {}

size_t linkedlist<A>::size() const
{
    return length;
}

bool linkedlist<A>::isempty() const
{
    return (head == NULL);
}

Exception::Exception() {}

std::string Exception::what_err() const
{
    return this->what_arg;
}

IndexError::IndexError(std::string what_arg)
{
    this->what_arg = what_arg;
}

ValueError::ValueError(std::string what_arg)
{
    this->what_arg = what_arg;
}

TypeError::TypeError(std::string what_arg)
{
    this->what_arg = what_arg;
}
