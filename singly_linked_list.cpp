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
void singly_linked_list<A>::extend(const linkedlist<A> &obj)
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
