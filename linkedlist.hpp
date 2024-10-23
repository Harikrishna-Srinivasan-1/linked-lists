#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <initializer_list>
#include <vector>

#include "./exception.hpp"

typedef signed long int64_t;
typedef unsigned long size_t;

template <typename A>
class linkedlist
{
    protected:
        typedef struct node
        {
            A value;
            struct node *next;
        } node;

        node **head, **tail;
        
        constexpr static node **gethead(const linkedlist<A> &obj);
        constexpr static node *getmiddle(node *head);
        constexpr static node **gettail(const linkedlist<A> &obj);
    public:
        class iterator
        {
            private:
                linkedlist<A>::node *ptr;

                iterator(linkedlist<A>::node *ptr);
            public:
                iterator();

                constexpr iterator &operator++();
                constexpr iterator &operator++(int);
                constexpr A &operator*();
                constexpr bool operator==(const iterator &it) const;
                constexpr bool operator!=(const iterator &it) const;

                ~iterator() = default;
        };

        class const_iterator
        {
            private:
                const linkedlist<A>::node *ptr;

                const_iterator(linkedlist<A>::node *ptr);
            public:
                const_iterator();

                constexpr const const_iterator &operator++();
                constexpr const const_iterator &operator++(int);
                constexpr const A &operator*() const;
                constexpr bool operator==(const const_iterator &it) const;
                constexpr bool operator!=(const const_iterator &it) const;

                ~const_iterator() = default;
        };

        linkedlist();

        virtual void prepend(const A &value) = 0;
        virtual void append(const A &value) = 0;
        virtual void insert(const int64_t &index, const A &value) = 0;
        virtual void insert(const int64_t &index, const linkedlist<A> &obj) = 0;
        virtual void insert(const int64_t &index, const std::initializer_list<A> &values) = 0;
        virtual void insert(const int64_t &index, const std::vector<A> &values) = 0;

        virtual void insert_in_order(const A &value) = 0;
        virtual void insert_in_order(const linkedlist<A> &obj) = 0;
        virtual void insert_in_order(const std::initializer_list<A> &values) = 0;
        virtual void insert_in_order(const std::vector<A> &values) = 0;

        virtual void extend(const linkedlist<A> &obj) = 0;
        virtual void extend(const std::initializer_list<A> &values) = 0;
        virtual void extend(const std::vector<A> &values) = 0;

        virtual void remove(const A &value) = 0;
        virtual A pop(const int64_t &index) = 0;
        virtual A pop() = 0;

        constexpr virtual size_t size() const;
        
        constexpr bool isempty() const;

        virtual bool contains(const A &value) const = 0;
        virtual int64_t index(const A &value) const = 0;
        virtual size_t count(const A &value) const = 0;
        
        virtual void reverse() = 0;
        virtual void sort() = 0;

        virtual A &operator[](const int64_t &index) = 0;
        virtual bool operator>(const linkedlist<A> &obj) const = 0;
        virtual bool operator<(const linkedlist<A> &obj) const = 0;
        virtual bool operator>=(const linkedlist<A> &obj) const = 0;
        virtual bool operator<=(const linkedlist<A> &obj) const = 0;
        virtual bool operator==(const linkedlist<A> &obj) const = 0;
        virtual bool operator!=(const linkedlist<A> &obj) const = 0;

        virtual operator A *() = 0;
        virtual operator std::vector<A>() = 0;

        virtual void show() = 0;

        virtual void clear() = 0;

        constexpr linkedlist<A>::iterator begin();
        constexpr linkedlist<A>::iterator end();
        constexpr const linkedlist<A>::const_iterator cbegin() const;
        constexpr const linkedlist<A>::const_iterator cend() const;

        template <typename B>
        friend B min(const linkedlist<B> &obj);

        template <typename B>
        friend B max(const linkedlist<B> &obj);

        template <typename B>
        friend size_t len(const linkedlist<B> &obj);

        virtual ~linkedlist() = default;
};

template <typename A>
A min(const linkedlist<A> &oAj);

template <typename A>
A max(const linkedlist<A> &obj);

template <typename A>
size_t len(const linkedlist<A> &obj);

#include "linkedlist.tpp"

#endif
