#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
};

template <typename A>
size_t len(const linkedlist<A> &obj);

class Exception
{
    protected:
        std::string what_arg;
    public:
        Exception();
        virtual std::string what_err() const;
};

class IndexError: public Exception
{
    public:
        IndexError(std::string what_arg);
};

class ValueError: public Exception
{
    public:
        ValueError(std::string what_arg);
};

class TypeError: public Exception
{
    public:
       TypeError(std::string what_arg);
};

#endif


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


#include "linkedlist.h"
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename A>
class singly_linked_list: public linkedlist<A>
{
    public:
        singly_linked_list();

        void prepend(const A &value);
        void append(const A &value);
        void insert(const A &value, const size_t &index);
        void insert_inorder(const A &value);
        void extend(const linkedlist<A> &obj);

        void remove(const A &value);
        A pop(const size_t &index);
        A pop();

        size_t size() const;

        size_t find(const A &value) const;
        size_t count(const A &value) const;

        A &operator[](const size_t &index);
        linkedlist<A> &operator+(const linkedlist<A> &obj);
        linkedlist<A> &operator=(const linkedlist<A> &obj);

        void show();

        void clear();
};

#endif



#include "singly_linked_list.h"


template <typename A>
singly_linked_list<A>::singly_linked_list():
linkedlist<A>::linkedlist() {}

template <typename A>
void singly_linked_list<A>::prepend(const A &value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->next = this->head;

    this->head = new_node;
}

template <typename A>
void singly_linked_list<A>::append(const A &value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->next = NULL;

    if (this->isempty())
    {
        this->head = new_node;
        this->length++;
        return;
    }

    node *ptr = this->head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    this->length++;
}

template <typename A>
void singly_linked_list<A>::insert(const A &value, const size_t &index)
{
    if (this->isempty() || index == 0 || index <= -(this->size()))
    {
        this->prepend(value);
        return;
    }

    if (index == -1 || index >= (this->size()) - 1)
    {
        this->append(value);
        return;
    }

    size_t curr_index = 0;
    if (index < 0)
    {
        curr_index = (this->size()) + index;
    }

    node *new_node = new node, *ptr = this->head;
    new_node->value = value;

    while (curr_index != index - 1)
    {
        ptr = ptr->next;
        curr_index++;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    this->length++;
}

template <typename A>
void singly_linked_list<A>::insert_inorder(const A &value)
{
    if (this->isempty())
    {
        this->prepend(value);
        return;
    }

    node *new_node = new node;
    new_node->value = value;

    if (this->head->value >= value)
    {
        new_node->next = this->head;
        this->head = new_node;
        this->length++;

        return;
    }

    node *ptr = this->head;
    while (ptr->next != NULL)
    {
        if (ptr->next->value >= value)
            break;
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    this->length++;
}

template <typename A>
void singly_linked_list::extend(const linkedlist<A> &obj)
{
    if (this->isempty())
    {
        this = obj;
        return;
    }
    if (obj.isempty())
    {
        return;
    }
}
template <typename A>
void singly_linked_list<A>::remove(const A &value)
{
    if (this->isempty())
        throw ValueError("ValueError: Removing from Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    node *ptr = this->head;
    if (ptr->value == value)
    {
        this->head = ptr->next;
        delete ptr;

        this->length--;
        return;
    }

    while (ptr->next != NULL)
    {
        if (ptr->next->value == value)
            break;
        ptr = ptr->next;
    }

    if (ptr == NULL)
        throw ValueError("ValueError: Removing `x`, non-element in the List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    
    this->length--;
}

template <typename A>
A singly_linked_list<A>::pop(const size_t &index)
{
    if (this->isempty())
        throw ValueError("ValueError: Pop from Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    if (index < -(this->size()) || index >= (this->size()))
        throw IndexError("IndexError: Pop index out of range in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    node *ptr = this->head;
    if (index == 0 || index == -(this->size()))
    {
        A value = ptr->value;
        this->head = ptr->next;
        delete ptr;

        this->length--;
        return value;
    }

    size_t curr_index = 0;
    if (index < 0)
    {
        curr_index = (this->size()) + index;
    }

    while (curr_index != index - 1)
    {
        ptr = ptr->next;
        curr_index++;
    }

    node *temp = ptr->next;
    ptr->next = temp->next;

    A value = temp->value;
    delete temp;
    this->length--;

    return value;
}

template <typename A>
A singly_linked_list<A>::pop()
{
    return this->pop(0);
}

template <typename A>
size_t singly_linked_list<A>::find(const A &value) const
{
    if (this->isempty())
        return NOT_FOUND;

    size_t curr_index = 0;
    node *ptr = this->head;
    while (ptr != NULL)
    {
        if (ptr->value == value)
            return curr_index;
        curr_index++;
        ptr = ptr->next;
    }

    return NOT_FOUND;
}

template <typename A>
size_t singly_linked_list<A>::count(const A &value) const
{
    size_t founds = 0;
    if (this->isempty())
        return founds;

    node *ptr = this->head;
    while (ptr != nullptr)
    {
        if (ptr->value == value)
            founds++;
        ptr = ptr->next;
    }

    return founds;
}

template <typename A>
A &singly_linked_list<A>::operator[](const size_t &index)
{
    if (this->isempty())
        throw IndexError("IndexError: Indexing an Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    if (index < -(this->size()) || index >= (this->size()))
        throw IndexError("IndexError: List index out of range in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    if (index == 0 || index == -(this->size()))
        return this->head->value;

    size_t curr_index = 0;
    if (index < 0)
    {
        curr_index = (this->size()) + index;
    }

    node *ptr = this>head;
    while (curr_index != index)
    {
        curr_index++;
        ptr = ptr->next;
    }

    return ptr->value;
}

template <typename A>
linkedlist<A> &singly_linked_list<A>::operator=(const linkedlist<A> &obj)
{
    this->clear();
    this->head = NULL;

    node *new_node = NULL, *ptr = obj.head;

    while (ptr != NULL)
    {
        new_node->value = ptr->value;

    }
}

template <typename A>
linkedlist<A> &singly_linked_list<A>::operator+(const linkedlist<A> &obj)
{
    // Do not send the address of this or obj, but only the copy of th values

    singly_linked_list<A> list;

    node *new_node = new node;
    new_node->value = this->head->value;
    list.head = new_node;

    node *ptr = this->head->next;
    while (ptr != nullptr)
    {
        new_node = new node;

        new_node->next = temp;
        new_node = temp;
        new_node->value = ptr->value;
    }

    new_node->next = obj.head;

    return list;
}

template <typename A>
void singly_linked_list<A>::show()
{
    std::cout << "[";

    if (this->isempty())
    {
        std::cout << "]" << std::endl;
        return;
    }

    node *ptr = this->head;
    while (ptr->next != NULL)
    {
        std::cout << ptr->value << ", ";
    }

    std::cout << ptr->value << "]" << std::endl;
}

template <typename A>
void singly_linked_list<A>::clear() 
{
    node *temp = NULL;
    
    while (this->isempty())
    {
        temp = this->head;
        this->head = this->head->next;

        delete temp;
        this->length--;
    }
}
