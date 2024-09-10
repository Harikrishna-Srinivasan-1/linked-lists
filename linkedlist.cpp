#include "linkedlist.h"


template <typename A>
linkedlist<A>::linkedlist():
head(nullptr), tail(nullptr) {}

template <typename A>
typename linkedlist<A>::node *linkedlist<A>::gethead(const linkedlist<A> &obj) 
{
    return obj.head;
}

template <typename A>
typename linkedlist<A>::node *linkedlist<A>::gettail(const linkedlist<A> &obj) 
{
    return obj.tail;
}

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

template <typename A>
size_t len(const linkedlist<A> &obj)
{
    size_t size = 0;
    typename linkedlist<A>::node *ptr = obj.head;

    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }

    return size;
}
