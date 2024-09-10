#include "singly_linked_list.h"


template <typename A>
singly_linked_list<A>::singly_linked_list():
linkedlist<A>::linkedlist(), length(0) {}

template <typename A>
singly_linked_list<A>::singly_linked_list(const singly_linked_list<A> &obj): linkedlist<A>::linkedlist()
{
    this->copy(obj);
}

template <typename A>
void singly_linked_list<A>::prepend(const A &value) 
{
    typename linkedlist<A>::node *new_node = new typename linkedlist<A>::node;
    new_node->value = value;
    new_node->next = this->head;

    if (this->isempty())
        this->tail = new_node;
    this->head = new_node;
    
    this->length++;
}

template <typename A>
void singly_linked_list<A>::append(const A &value)
{
    typename linkedlist<A>::node *new_node = new typename linkedlist<A>::node;
    new_node->value = value;
    new_node->next = nullptr;

    if (this->isempty())
    {
        this->head = new_node;
        this->tail = new_node;
        
        this->length++;
        return;
    }

    this->tail->next = new_node;
    this->tail = new_node;
    
    this->length++;
}

template <typename A>
void singly_linked_list<A>::insert(const int64_t &index, const A &value)
{
    if (this->isempty() || index == 0L || index <= -(int64_t)(this->size()))
    {
        this->prepend(value);
        return;
    }

    if (index == -1L || index >= (int64_t)(this->size()) - 1L)
    {
        this->append(value);
        return;
    }

    int64_t curr_index = 0L;
    if (index < 0L)
        curr_index = (int64_t)(this->size()) + index;

    typename linkedlist<A>::node *new_node = new typename linkedlist<A>::node, *ptr = this->head;
    new_node->value = value;
    while (curr_index != index - 1L)
    {
        ptr = ptr->next;
        curr_index++;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    
    this->length++;
}

template <typename A>
void singly_linked_list<A>::insert_in_order(const A &value)
{
    if (this->isempty() || this->head->value >= value)
    {
        this->prepend(value);
        return;
    }

    if (this->tail->value <= value)
    {
        this->append(value);
        return;
    }

    typename linkedlist<A>::node *new_node = new typename linkedlist<A>::node, *ptr = this->head;
    new_node->value = value;
    while (ptr->next != this->tail)
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
    if (obj.isempty())
        return;
    
    typename linkedlist<A>::node *ptr = linkedlist<A>::gethead(obj);
    while (ptr != nullptr)
    {
        this->append(ptr->value);
        ptr = ptr->next;
    }
}

template <typename A>
void singly_linked_list<A>::remove(const A &value)
{
    if (this->isempty())
        throw ValueError("ValueError: Removing from Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__ + "\n");

    typename linkedlist<A>::node *ptr = this->head;
    if (ptr->value == value)
    {
        this->head = ptr->next;
        delete ptr;

        this->length--;
        return;
    }

    while (ptr->next != nullptr)
    {
        if (ptr->next->value == value)
            break;
        ptr = ptr->next;
    }

    if (ptr->next == nullptr)
        throw ValueError("ValueError: Removing `x`, non-element in the List in line " + std::to_string(__LINE__) + " in file: " + __FILE__ + "\n");

    if (ptr->next == this->tail)
        this->tail = ptr;

    typename linkedlist<A>::node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    
    this->length--;
}

template <typename A>
A singly_linked_list<A>::pop(const int64_t &index)
{
    if (this->isempty())
        throw ValueError("ValueError: Pop from Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__ + "\n");

    if (index < -(int64_t)(this->size()) || index >= (int64_t)(this->size()))
        throw IndexError("IndexError: Pop index out of range in line " + std::to_string(__LINE__) + " in file: " + __FILE__ + "\n");

    typename linkedlist<A>::node *ptr = this->head;
    if (index == 0L || index == -(int64_t)(this->size()))
    {
        A value = ptr->value;
        this->head = ptr->next;
        delete ptr;
        if (this->isempty())
            this->tail = nullptr;

        this->length--;
        return value;
    }

    int64_t curr_index = 0L;
    if (index < 0L)
        curr_index = -(int64_t)(this->size());

    while (curr_index != index - 1L)
    {
        ptr = ptr->next;
        curr_index++;
    }
    
    if (ptr->next == this->tail)
        this->tail = ptr;

    typename linkedlist<A>::node *temp = ptr->next;
    ptr->next = temp->next;

    A value = temp->value;
    delete temp;
    
    this->length--;
    return value;
}

template <typename A>
A singly_linked_list<A>::pop()
{
    return this->pop(-1L);
}

template <typename A>
size_t singly_linked_list<A>::find(const A &value) const
{
    if (this->isempty())
        return NOT_FOUND;

    size_t curr_index = 0;
    typename linkedlist<A>::node *ptr = this->head;
    while (ptr != nullptr)
    {
        if (ptr->value == value)
            return curr_index;
        curr_index++;
        ptr = ptr->next;
    }

    return curr_index;
}

template <typename A>
size_t singly_linked_list<A>::count(const A &value) const
{
    size_t founds = 0;
    if (this->isempty())
        return founds;

    typename linkedlist<A>::node *ptr = this->head;
    while (ptr != nullptr)
    {
        if (ptr->value == value)
            founds++;
        ptr = ptr->next;
    }

    return founds;
}

template <typename A> 
void singly_linked_list<A>::reverse()
{
    typename linkedlist<A>::node *current = this->head, *prev = nullptr, *next_node;
    this->tail = this->head;
    while (current != nullptr)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }

    this->head = prev;
}

// template <typename A> void singly_linked_list<A>::sort() {}

template <typename A>
singly_linked_list<A> &singly_linked_list<A>::copy(const linkedlist<A> &obj) 
{
    if (this == &obj)
        return *this;
    
    this->clear();
    typename linkedlist<A>::node *ptr = linkedlist<A>::gethead(obj);
    while (ptr != nullptr)
    {
        this->append(ptr->value);
        ptr = ptr->next;
    }

    return *this;
}

template <typename A>
A &singly_linked_list<A>::operator[](const int64_t &index)
{
    if (this->isempty())
        throw IndexError("IndexError: Indexing an Empty List in line " + std::to_string(__LINE__) + " in file: " + __FILE__ + "\n");

    if (index < -(int64_t)(this->size()) || index >= (int64_t)(this->size()))
        throw IndexError("IndexError: List index out of range in line " + std::to_string(__LINE__) + " in file: " + __FILE__ + "\n");

    if (index == 0L || index == -(int64_t)(this->size()))
        return this->head->value;

    int64_t curr_index = 0L;
    if (index < 0L)
        curr_index = (int64_t)(this->size()) + index;

    typename linkedlist<A>::node *ptr = this->head;
    while (curr_index != index)
    {
        curr_index++;
        ptr = ptr->next;
    }

    return ptr->value;
}

template <typename A>
singly_linked_list<A> &singly_linked_list<A>::operator=(const singly_linked_list<A> &obj)
{
    return this->copy(obj);
}

// TODO: Dummy/not fully working operator+, concatenate and return the local obj, `linkedlist<A> &` needs non-local obj
template <typename A>
singly_linked_list<A> singly_linked_list<A>::operator+(const linkedlist<A> &obj)
{
    // Do not return the address of this or obj, return copy of the values
    singly_linked_list<A> list = *this;
    list.extend(obj);

    return list;
}

template <typename A>
singly_linked_list<A> singly_linked_list<A>::operator*(const size_t &times) 
{
    singly_linked_list<A> list = *this;
    for (size_t i = times - 1; i != 0; i--)
        list.extend(*this);

    return list;
}

template <typename A>
bool singly_linked_list<A>::operator>(const linkedlist<A> &obj) const 
{
    typename linkedlist<A>::node *ptr1 = this->head, *ptr2 = linkedlist<A>::gethead(obj);
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value > ptr2->value)
            return true;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == nullptr)
        return false;
    return true;
}

template <typename A>
bool singly_linked_list<A>::operator<(const linkedlist<A> &obj) const 
{
    typename linkedlist<A>::node *ptr1 = this->head, *ptr2 = linkedlist<A>::gethead(obj);
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value < ptr2->value)
            return true;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == nullptr)
        return true;
    return false;
}

template <typename A>
bool singly_linked_list<A>::operator>=(const linkedlist<A> &obj) const 
{
    typename linkedlist<A>::node *ptr1 = this->head, *ptr2 = linkedlist<A>::gethead(obj);
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value >= ptr2->value)
            return true;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == nullptr)
        return false;
    return true;
}

template <typename A>
bool singly_linked_list<A>::operator<=(const linkedlist<A> &obj) const 
{
    typename linkedlist<A>::node *ptr1 = this->head, *ptr2 = linkedlist<A>::gethead(obj);
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value <= ptr2->value)
            return true;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == nullptr)
        return true;
    return false;
}

template <typename A>
bool singly_linked_list<A>::operator==(const linkedlist<A> &obj) const 
{
    typename linkedlist<A>::node *ptr1 = this->head, *ptr2 = linkedlist<A>::gethead(obj);
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->value != ptr2->value)
            return false;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == ptr2)
        return true;
    return false;
}

template <typename A>
bool singly_linked_list<A>::operator!=(const linkedlist<A> &obj) const
{
    return !(*this == obj);
}

template <typename A>
void singly_linked_list<A>::show()
{
    std::cout << "[";

    if (this->isempty())
    {
        std::cout << "]";
        return;
    }

    typename linkedlist<A>::node *ptr = this->head;
    while (ptr != this->tail)
    {
        std::cout << ptr->value << ", ";
        ptr = ptr->next;
    }

    std::cout << ptr->value << "]";
}

template <typename A>
void singly_linked_list<A>::clear() 
{
    typename linkedlist<A>::node *temp = nullptr;
    while (!this->isempty())
    {
        temp = this->head;
        this->head = this->head->next;

        delete temp;
    }

    this->tail = nullptr;
    this->length = 0;
}

template <typename A>
singly_linked_list<A> operator*(const size_t &times, singly_linked_list<A> &obj)
{
    return obj * times;
}


template <typename A>
std::ostream &operator<<(std::ostream &out, singly_linked_list<A> &obj)
{
    obj.show();
    return out;
}

template <typename A>
singly_linked_list<A>::~singly_linked_list() 
{
    this->clear();
}
