#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <exception>
#include <iostream>

template <typename A>
class linkedlist
{
    protected:
        typedef struct node
        {
            A value;
            struct node *next;
        } node;

        node *head, *tail;
        size_t length;
        
        static node *gethead(const linkedlist<A> &obj);
        static node *gettail(const linkedlist<A> &obj);
    public:
        linkedlist();

        virtual void prepend(const A &value) = 0;
        virtual void append(const A &value) = 0;
        virtual void insert(const A &value, const int64_t &index) = 0;
        virtual void insert_inorder(const A &value) = 0;
        virtual void extend(const linkedlist<A> &obj) = 0;

        virtual void remove(const A &value) = 0;
        virtual A pop(const int64_t &index) = 0;
        virtual A pop() = 0;

        virtual size_t size() const;

        virtual size_t find(const A &value) const = 0;
        virtual size_t count(const A &value) const = 0;

        virtual bool isempty() const;
        
        virtual void reverse() = 0;
        // virtual void sort() = 0;   

        virtual A &operator[](const int64_t &index) = 0;
        virtual bool operator>(const linkedlist<A> &obj) const = 0;
        virtual bool operator<(const linkedlist<A> &obj) const = 0;
        virtual bool operator>=(const linkedlist<A> &obj) const = 0;
        virtual bool operator<=(const linkedlist<A> &obj) const = 0;
        virtual bool operator==(const linkedlist<A> &obj) const = 0;
        virtual bool operator!=(const linkedlist<A> &obj) const = 0;

        virtual void clear() = 0;

        template <typename B>
        friend size_t len(const linkedlist<B> &obj);
        

        virtual ~linkedlist();
};

template <typename A>
size_t len(const linkedlist<A> &obj);

#endif
