#include "linkedlist.h"


template <typename A>
linkedlist<A>::linkedlist():
head(nullptr), length(0), tail(nullptr) {}

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

template <typename A>
linkedlist<A>::~linkedlist() {}

// TODO: Implement len(); protected variable cannot be accessed, but declared as `friend`
template <typename A>
size_t len(const linkedlist<A> &obj) {return -1;}
/*
{
    size_t size = 0;
    typename linkedlist<A>::node *ptr = obj.head;

    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }

    return size;
}*/
