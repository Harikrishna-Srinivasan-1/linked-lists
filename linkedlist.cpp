#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <exception>
#include <iostream>

const size_t NOT_FOUND = -1;

template <typename A>
class linkedlist
{
    protected:
        typedef struct node
        {
            A value;
            struct node *next;
        } node;

        node *head;
        int length;
    public:
        linkedlist();

        virtual void prepend(const A &value) = 0;
        virtual void append(const A &value) = 0;
        virtual void insert(const A &value, const size_t &index) = 0;
        virtual void insert_inorder(const A &value) = 0;
        virtual void extend(const linkedlist<A> &obj) = 0;

        virtual void remove(const A &value) = 0;
        virtual A pop(const size_t &index) = 0;
        virtual A pop() = 0;

        virtual size_t size() const;

        virtual size_t find(const A &value) const = 0;
        virtual size_t count(const A &value) const = 0;

        virtual bool isempty() const;

        virtual A &operator[](const size_t &index) = 0;
        virtual linkedlist<A> &operator=(const linkedlist<A> &obj) = 0;
        virtual linkedlist<A> &operator+(const linkedlist<A> &obj) = 0;

        virtual void clear() = 0;
        
        template <typename B>
        friend size_t len(const linkedlist<B> &obj);

        virtual ~linkedlist();
};

template <typename A>
size_t len(const linkedlist<A> &obj);

class Exception: virtual public std::exception 
{
    protected:
        std::string what_arg;
    public:
        Exception();
        virtual std::string what_err() const;
        virtual ~Exception();
};

class IndexError: public Exception
{
    public:
        IndexError(std::string what_arg);
        ~IndexError();
};

class ValueError: public Exception
{
    public:
        ValueError(std::string what_arg);
        ~ValueError();
};

class TypeError: public Exception
{
    public:
       TypeError(std::string what_arg);
       ~TypeError();
};

#endif
