#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "linkedlist.cpp"
#include "exception.cpp"

template <typename A>
class singly_linked_list: public linkedlist<A>
{
    private:
    public:
        singly_linked_list();
        singly_linked_list(const singly_linked_list<A> &obj);

        void prepend(const A &value);
        void append(const A &value);
        void insert(const int64_t &index, const A &value);
        void insert_in_order(const A &value);
        void extend(const linkedlist<A> &obj);

        void remove(const A &value);
        A pop(const int64_t &index);
        A pop();

        size_t find(const A &value) const;
        size_t count(const A &value) const;

        void reverse();
        // void sort();

        singly_linked_list<A> &copy(const linkedlist<A> &obj);

        A &operator[](const int64_t &index);
        singly_linked_list<A> operator+(const linkedlist<A> &obj);
        singly_linked_list<A> &operator=(const singly_linked_list<A> &obj);
        singly_linked_list<A> operator*(const size_t &times);
        bool operator>(const linkedlist<A> &obj) const;
        bool operator<(const linkedlist<A> &obj) const;
        bool operator>=(const linkedlist<A> &obj) const;
        bool operator<=(const linkedlist<A> &obj) const;
        bool operator==(const linkedlist<A> &obj) const;
        bool operator!=(const linkedlist<A> &obj) const;

        void show();

        void clear();

        template <typename B>
        friend singly_linked_list<B> operator*(const size_t &times, const singly_linked_list<B> &obj);
        
        template <typename B>
        friend std::ostream &operator<<(std::ostream &out, singly_linked_list<B> &obj);

        ~singly_linked_list();
};

template <typename A>
singly_linked_list<A> operator*(const size_t &times, singly_linked_list<A> &obj);

template <typename A>
std::ostream &operator<<(std::ostream &out, singly_linked_list<A> &obj);

#endif
