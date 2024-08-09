#include "singly_linked_list.h"


singly_linked_list<A>::singly_linked_list():
linkedlist<A>::linkedlist() {}

void singly_linked_list<A>::prepend(const A &value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->next = head;

    head = new_node;
}

void singly_linked_list<A>::append(const A &value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->next = NULL;

    if (isempty())
    {
        head = new_node;
        length++;
        return;
    }

    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    length++;
}

void singly_linked_list<A>::insert(const A &value, const size_t &index)
{
    if (isempty() || index == 0 || index <= -(this->size()))
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

    node *new_node = new node, *ptr = head;
    new_node->value = value;

    while (curr_index != index - 1)
    {
        ptr = ptr->next;
        curr_index++;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    length++;
}

void singly_linked_list<A>::insert_inorder(const A &value)
{
    if (isempty())
    {
        this->prepend(value);
        return;
    }

    node *new_node = new node, *ptr = head;
    new_node->value = value;

    if (head->value >= value)
    {
        new_node->next = head;
        head = new_node;
        length++;

        return;
    }

    while (ptr->next != NULL)
    {
        if (ptr->next->value >= value)
            break;
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    length++;
}


void singly_linked_list<A>::remove(const A &value)
{
    if (isempty())
        throw ValueError("ValueError: Removing from Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    node *ptr = head;
    if (head->value == value)
    {
        head = ptr->next;
        delete ptr;

        length--;
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
    length--;
}

A singly_linked_list<A>::pop(const size_t &index)
{
    if (isempty())
        throw ValueError("ValueError: Pop from Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    if (index < -(this->size()) || index >= (this->size()))
        throw IndexError("IndexError: Pop index out of range in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    node *ptr = head;
    if (index == 0 || index == -(this->size()))
    {
        A value = ptr->value;
        head = head->next;
        delete ptr;

        length--;
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
    length--;

    return value;
}

A singly_linked_list<A>::pop()
{
    return this->pop(0);
}

size_t singly_linked_list<A>::find(const A &value) const
{
    if (isempty())
        return NOT_FOUND;

    size_t curr_index = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->value == value)
            return curr_index;
        curr_index++;
        ptr = ptr->next;
    }

    return NOT_FOUND;
}

size_t singly_linked_list<A>::count(const A &value) const
{
    size_t founds = 0;
    if (isempty())
        return founds;

    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->value == value)
            founds++;
        ptr = ptr->next;
    }

    return founds;
}

A &singly_linked_list<A>::operator[](const size_t &index)
{
    if (isempty())
        throw IndexError("IndexError: Indexing an Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    if (index < -(this->size()) || index >= (this->size()))
        throw IndexError("IndexError: List index out of range in line " + std::to_string(__LINE__) + " in file: " + __FILE__);

    if (index == 0 || index == -(this->size()))
        return head->value;

    size_t curr_index = 0;
    if (index < 0)
    {
        curr_index = (this->size()) + index;
    }

    node *ptr = head;
    while (curr_index != index)
    {
        curr_index++;
        ptr = ptr->next;
    }

    return ptr->value;
}

linkedlist<A> singly_linked_list<A>::operator+(linkedlist<A> &obj)
{
    if (this->head == NULL)
        return obj;

    singly_linked_list<A> list;

    node *new_node = new node;
    new_node->value = head->value;
    list.head = new_node;

    node *ptr = head->next, *temp = NULL;
    while (ptr != NULL)
    {
        temp = new node;

        new_node->next = temp;
        new_node = temp;
        new_node->value = ptr->value;
    }

    new_node->next = obj.head;

    return list;
}

void singly_linked_list<A>::show()
{
    std::cout << "[";

    if (isempty())
    {
        std::cout << "]" << std::endl;
        return;
    }

    node *ptr = head;
    while (ptr->next != NULL)
    {
        std::cout << ptr->value << ", ";
    }

    std::cout << ptr->value << "]" << std::endl;
}

void singly_linked_list<A>::freed() {}
