#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <initializer_list>
#include <vector>

typedef signed long int64_t;
typedef unsigned long size_t;

const int64_t NOT_FOUND = -1L;

template <typename A>
class linkedlist
{
    protected:
        typedef struct node
        {
            A value;
            struct node *next;

            node() = default;
        } node;

        node *head, *tail;
        
        static node *gethead(const linkedlist<A> &obj);
        static node *getmiddle(node *head);
        static node *gettail(const linkedlist<A> &obj);
    public:
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

        virtual size_t size() const;
        
        bool isempty() const;

        virtual int64_t find(const A &value) const = 0;
        virtual A find_min() const = 0;
        virtual A find_max() const = 0;
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

        virtual void show() const = 0;
        
        virtual void clear() = 0;

        template <typename B>
        friend size_t len(const linkedlist<B> &obj);
        

        virtual ~linkedlist() = default;
};

template <typename A>
size_t len(const linkedlist<A> &obj);

#include "linkedlist.tpp"

#endif
