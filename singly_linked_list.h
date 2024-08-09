#include "linkedlist.h"
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename A>;
class singly_linked_list: public linkedlist
{
    public:
        singly_linked_list();

        void prepend(const A &value);
        void append(const A &value);
        void insert(const A &value, const size_t &index);
        void insert_inorder(const A &value);
        void extend(const linkedlist &obj);

        void remove(const A &value);
        A pop(const size_t &index);
        A pop();

        size_t size() const;

        size_t find(const A &value) const;
        size_t count(const A &value) const;

        A &operator[](const size_t &index);
        linkedlist<A> operator+(linkedlist<A> &obj);

        void show();

        void freed();
};

#endif

