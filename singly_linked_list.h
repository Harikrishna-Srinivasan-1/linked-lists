#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "linkedlist.h"

template <typename A>
class singly_linked_list: public linkedlist<A>
{
    public:
        singly_linked_list();

        void prepend(const A &value);
        void append(const A &value);
        void insert(const A &value, const int64_t &index);
        void insert_inorder(const A &value);
        void extend(const linkedlist<A> &obj);

        void remove(const A &value);
        A pop(const int64_t &index);
        A pop();

        size_t find(const A &value) const;
        size_t count(const A &value) const;

        A &operator[](const int64_t &index);
        linkedlist<A> &operator+(const linkedlist<A> &obj);
        linkedlist<A> &operator=(const linkedlist<A> &obj);

        void show();

        void clear();

        ~singly_linked_list();
};

#endif
