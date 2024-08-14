#include "linkedlist.h"

template <typename A>

linkedlist<A>::linkedlist():
this->head(NULL), this->length(0) {}

template <typename A>
size_t linkedlist<A>::size() const
{
    return this->length;
}

template <typename A>
bool linkedlist<A>::isempty() const
{
    return (this->head == nullptr);
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

template <typename A>
size_t len(const linkedlist<A> &obj)
{
    size_t size = 0;
    node *ptr = obj.head;

    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }

    return size;
}
