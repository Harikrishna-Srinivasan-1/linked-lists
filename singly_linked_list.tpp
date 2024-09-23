#include "singly_linked_list.h"


/**
 * @brief Default constructor for singly_linked_list.
 */
template <typename A>
singly_linked_list<A>::singly_linked_list(): linkedlist<A>::linkedlist(), length(0) {}

/**
 * @brief Copy constructor for singly_linked_list.
 * @param obj The singly_linked_list object to copy from.
 */
template <typename A>
singly_linked_list<A>::singly_linked_list(const singly_linked_list<A> &obj): linkedlist<A>::linkedlist(), length(0) 
{
    this->copy(obj);
}

/**
 * @brief Constructor from an initializer list.
 * @param obj Initializer list of values to initialize the list with.
 */
template <typename A>
singly_linked_list<A>::singly_linked_list(const std::initializer_list<A> &values): linkedlist<A>::linkedlist(), length(0)
{
    this->extend(values);
}

/**
 * @brief Constructor from an array.
 * @tparam N The size of the array.
 * @param array Array of values to initialize the list with.
 */
template <typename A>
template <size_t N>
singly_linked_list<A>::singly_linked_list(const A (&array)[N]): linkedlist<A>::linkedlist(), length(0)
{
    this->extend(array);
}

/**
 * @brief Constructor from a vector.
 * @param values Vector of values to initialize the list with.
 */
template <typename A>
singly_linked_list<A>::singly_linked_list(const std::vector<A> &values): linkedlist<A>::linkedlist(), length(0)
{
    this->extend(values);
}

/**
 * @brief Move constructor for singly_linked_list.
 * @param obj The singly_linked_list object to move from.
 */
template <typename A>
singly_linked_list<A>::singly_linked_list(singly_linked_list<A> &&obj) noexcept
{
    this->clear();
    this->length = obj.size();
    this->head = linkedlist<A>::gethead(obj);
    this->tail = linkedlist<A>::gettail(obj);

    obj.head = nullptr;
    obj.tail = nullptr;
    obj.length = 0;
}

/**
 * @brief Assignment operator for copying from another singly_linked_list.
 * @param obj The singly_linked_list object to copy from.
 * @return A reference to this singly_linked_list.
 */
template <typename A>
singly_linked_list<A> &singly_linked_list<A>::operator=(const singly_linked_list<A> &obj)
{
    return this->copy(obj);
}

/**
 * @brief Assignment operator for assigning from an initializer list.
 * @param values The initializer list containing the values to assign.
 * @return A reference to this singly_linked_list.
 */
template <typename A>
singly_linked_list<A>& singly_linked_list<A>::operator=(const std::initializer_list<A>& values) 
{
    this->clear();
    this->extend(values);
    return *this;
}

/**
 * @brief Assignment operator for assigning from a static array.
 * @tparam N The size of the array.
 * @param array The static array containing the values to assign.
 * @return A reference to this singly_linked_list.
 */
template <typename A>
template <size_t N>
singly_linked_list<A>& singly_linked_list<A>::operator=(const A (&array)[N]) 
{
    this->clear();
    this->extend(array);
    return *this;
}

/**
 * @brief Assignment operator for copying from another singly_linked_list.
 * @param obj The singly_linked_list object to copy from.
 * @return A reference to this singly_linked_list.
 */
template <typename A>
singly_linked_list<A>& singly_linked_list<A>::operator=(const singly_linked_list<A>& obj) 
{
    this->clear();
    this->extend(obj);
    return *this;
}


/**
 * @brief Move assignment operator for transferring from another singly_linked_list.
 * @param obj The singly_linked_list object to move from.
 * @return A reference to this singly_linked_list.
 */
template <typename A>
singly_linked_list<A> &singly_linked_list<A>::operator=(singly_linked_list<A> &&obj) noexcept
{
    this->length = obj.size();
    this->head = linkedlist<A>::gethead(obj);
    this->tail = linkedlist<A>::gettail(obj);

    obj.head = nullptr;
    obj.tail = nullptr;
    obj.length = 0;

    return *this;
}

/**
 * @brief Prepend a value to the list.
 * @param value The value to prepend.
 */
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

/**
 * @brief Append a value to the list.
 * @param value The value to append.
 */
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

/**
 * @brief Insert a value at a specific index.
 * @param index The position at which to insert the value.
 * @param value The value to insert.
 */
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
        curr_index = -(int64_t)(this->size());

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

/**
 * @brief Insert a linked list at a specific index.
 * @param index The position at which to insert the linked list.
 * @param obj The linked list to insert.
 */
template <typename A>
void singly_linked_list<A>::insert(const int64_t &index, const linkedlist<A> &obj)
{
    int64_t curr_index = index;
    typename linkedlist<A>::node *ptr = linkedlist<A>::gethead(obj);
    while (ptr != nullptr)
    {
        this->insert(curr_index++, ptr->value);
        ptr = ptr->next;
    }
}

/**
 * @brief Insert an initializer list of values at a specific index.
 * @param index The position at which to insert the values.
 * @param values The initializer list of values to insert.
 */
template <typename A>
void singly_linked_list<A>::insert(const int64_t &index, const std::initializer_list<A> &values)
{
    int64_t curr_index = index;
    for (const A &value: values)
        this->insert(curr_index++, value);
}

/**
 * @brief Insert an array at a specific index.
 * @tparam N The size of the array.
 * @param index The position at which to insert the array.
 * @param array The array of values to insert.
 */
template <typename A>
template <size_t N>
void singly_linked_list<A>::insert(const int64_t &index, const A (&array)[N])
{
    this->insert(index, std::vector<A>(array, array + N));
}

/**
 * @brief Insert a vector of values at a specific index.
 * @param index The position at which to insert the vector.
 * @param values The vector of values to insert.
 */
template <typename A>
void singly_linked_list<A>::insert(const int64_t &index, const std::vector<A> &values)
{
    int64_t curr_index = index;
    for (typename std::vector<A>::const_iterator it = values.begin(); it != values.end(); it++)
        this->insert(curr_index++, *it);
}

/**
 * @brief Insert a value into the list in sorted index.
 * @param value The value to insert.
 */
template <typename A>
void singly_linked_list<A>::insert_in_order(const A &value)
{
    if (this->isempty() || this->head->value >= value)
    {
        this->prepend(value);
        return;
    }

    typename linkedlist<A>::node *new_node = new typename linkedlist<A>::node, *ptr = this->head;
    new_node->value = value;
    while (ptr->next != nullptr)
    {
        if (ptr->next->value >= value)
            break;
        ptr = ptr->next;
    }

    if (ptr->next == nullptr)
        this->tail = new_node;
    new_node->next = ptr->next;
    ptr->next = new_node;
    
    this->length++;
}

/**
 * @brief Insert a linked list into the list in sorted index.
 * @param index The position at which to insert the linked list.
 * @param obj The linked list to insert.
 */
template <typename A>
void singly_linked_list<A>::insert_in_order(const linkedlist<A> &obj)
{
    typename linkedlist<A>::node *ptr = linkedlist<A>::gethead(obj);
    while (ptr != nullptr)
    {
        this->insert_in_order(ptr->value);
        ptr = ptr->next;
    }
}

/**
 * @brief Insert an initializer list of values into the list in sorted index.
 * @param index The position at which to insert the values.
 * @param values The initializer list of values to insert.
 */
template <typename A>
void singly_linked_list<A>::insert_in_order(const std::initializer_list<A> &values)
{
    for (const A &value: values)
        this->insert_in_order(value);
}

/**
 * @brief Insert an array into the list in sorted index.
 * @tparam N The size of the array.
 * @param index The position at which to insert the array.
 * @param array The array of values to insert.
 */
template <typename A>
template <size_t N>
void singly_linked_list<A>::insert_in_order(const A (&array)[N])
{
    this->insert_in_order(std::vector<A> (array, array + N));
}

/**
 * @brief Inserts multiple values into the singly linked list in order.
 *
 * This method inserts the values from the given vector into the list in order.
 *
 * @param index The index at which to start inserting the values.
 * @param values A vector containing the values to be inserted.
 */
template <typename A>
void singly_linked_list<A>::insert_in_order(const std::vector<A> &values)
{
    for (typename std::vector<A>::const_iterator it = values.begin(); it != values.end(); it++)
        this->insert_in_order(*it);
}

/**
 * @brief Extends the singly linked list with the contents of another linked list.
 *
 * This method appends the nodes from the provided linked list to the current list.
 *
 * @param obj The linked list to be extended.
 */
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

/**
 * @brief Extends the singly linked list with the contents of an initializer list.
 *
 * This method appends the values from the provided initializer list to the current list.
 *
 * @param values An initializer list containing the values to be appended.
 */
template <typename A>
void singly_linked_list<A>::extend(const std::initializer_list<A> &values)
{
    for (const A &value: values)
        this->append(value);
}

/**
 * @brief Extends the singly linked list with the contents of an array.
 *
 * This method appends the values from the provided array to the current list.
 *
 * @tparam N The size of the array.
 * @param array An array containing the values to be appended.
 */
template <typename A>
template <size_t N>
void singly_linked_list<A>::extend(const A (&array)[N])
{
    this->extend(std::vector<A>(array, array + N));
}

/**
 * @brief Extends the singly linked list with the contents of a vector.
 *
 * This method appends the values from the provided vector to the current list.
 *
 * @param values A vector containing the values to be appended.
 */
template <typename A>
void singly_linked_list<A>::extend(const std::vector<A> &values)
{
    for (typename std::vector<A>::const_iterator it = values.begin(); it != values.end(); it++)
        this->append(*it);
}

/**
 * @brief Removes the first occurrence of a specific value from the singly linked list.
 *
 * This method removes the first node containing the specified value. If the value is not found, an exception is thrown.
 *
 * @param value The value to be removed.
 * @throws VALUE_ERROR If the list is empty or the value is not found.
 */
template <typename A>
void singly_linked_list<A>::remove(const A &value)
{
    if (this->isempty())
        throw VALUE_ERROR("Removing from Empty List");

    typename linkedlist<A>::node *ptr = this->head;
    if (ptr->value == value)
    {
        this->head = ptr->next;
        delete ptr;

        this->head = this->tail = nullptr;
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
        throw VALUE_ERROR("Removing `x`, non-element in the List");

    if (ptr->next == this->tail)
        this->tail = ptr;

    typename linkedlist<A>::node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
    
    temp = nullptr;
    this->length--;
}

/**
 * @brief Pops and returns the value at a specific index from the singly linked list.
 *
 * This method removes and returns the node at the specified index. Negative indices count from the end.
 *
 * @param index The index of the node to be popped.
 * @return The value of the node at the specified index.
 * @throws INDEX_ERROR If the list is empty or the index is out of range.
 */
template <typename A>
A singly_linked_list<A>::pop(const int64_t &index)
{
    if (this->isempty())
        throw INDEX_ERROR("Pop from Empty List");

    if (index < -(int64_t)(this->size()) || index >= (int64_t)(this->size()))
        throw INDEX_ERROR("Pop index out of range");

    typename linkedlist<A>::node *ptr = this->head;
    if (index == 0L || index == -(int64_t)(this->size()))
    {
        A value = ptr->value;
        this->head = ptr->next;
        delete ptr;

        this->head = nullptr;
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
    
    temp = nullptr;
    this->length--;
    return value;
}

/**
 * @brief Pops and returns the last value from the singly linked list.
 *
 * This method removes and returns the last node from the list.
 *
 * @return The value of the last node.
 */
template <typename A>
A singly_linked_list<A>::pop()
{
    return this->pop(-1L);
}

/**
 * @brief Returns the number of elements in the singly linked list.
 *
 * @return The number of elements in the list.
 */
template <typename A>
size_t singly_linked_list<A>::size() const
{
    return this->length;
}

/**
 * @brief Finds the index of the first occurrence of a specific value in the singly linked list.
 *
 * This method returns the index of the first node containing the specified value. If the value is not found, it returns the size of the list.
 *
 * @param value The value to search for.
 * @return The index of the value in the list, or the size of the list if the value is not found.
 */
template <typename A>
int64_t singly_linked_list<A>::find(const A &value) const
{
    if (this->isempty())
        return NOT_FOUND;

    size_t curr_index = 0;
    typename linkedlist<A>::node *ptr = this->head;
    while (ptr != nullptr)
    {
        if (ptr->value == value)
            return curr_index;
        ptr = ptr->next;
        curr_index++;
    }

    return curr_index;
}

/**
 * @brief Finds and returns the minimum value in the singly linked list.
 *
 * This method returns the smallest value in the list. An exception is thrown if the list is empty.
 *
 * @return The minimum value in the list.
 * @throws VALUE_ERROR If the list is empty.
 */
template <typename A>
A singly_linked_list<A>::find_min() const
{
    if (this->isempty())
        throw VALUE_ERROR("Finding min in empty list");

    A min_value = this->head->value;
    typename linkedlist<A>::node *ptr = this->head->next;

    while (ptr != nullptr)
    {
        if (ptr->value < min_value)
            min_value = ptr->value;
        ptr = ptr->next;
    }

    return min_value;
}

/**
 * @brief Finds and returns the maximum value in the singly linked list.
 *
 * This method returns the largest value in the list. An exception is thrown if the list is empty.
 *
 * @return The maximum value in the list.
 * @throws VALUE_ERROR If the list is empty.
 */
template <typename A>
A singly_linked_list<A>::find_max() const
{
    if (this->isempty())
        throw VALUE_ERROR("Finding max in empty list");

    A max_value = this->head->value;
    typename linkedlist<A>::node *ptr = this->head->next;

    while (ptr != nullptr)
    {
        if (ptr->value > max_value)
            max_value = ptr->value;
        ptr = ptr->next;
    }

    return max_value;
}

/**
 * @brief Counts the number of occurrences of a specific value in the singly linked list.
 *
 * This method counts how many times the specified value appears in the list.
 *
 * @param value The value to count.
 * @return The number of occurrences of the value.
 */
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

/**
 * @brief Reverses the order of nodes in the singly linked list.
 *
 * This method reverses the linked list in place.
 */
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

/**
 * @brief Sorts the singly linked list in ascending order.
 *
 * This method sorts the list using merge sort.
 */
template <typename A>
void singly_linked_list<A>::sort() 
{
    if (this->head == nullptr || this->head->next == nullptr)
        return;
    
    this->head = singly_linked_list<A>::mergesort(this->head);
}

/**
 * @brief Recursively sorts the list using merge sort.
 *
 * @param head The head of the list to be sorted.
 * @return The head of the sorted list.
 */
template <typename A>
typename linkedlist<A>::node *singly_linked_list<A>::mergesort(typename linkedlist<A>::node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    typename linkedlist<A>::node *middle = linkedlist<A>::getmiddle(head), *next_of_middle = middle->next;
    middle->next = nullptr;

    typename linkedlist<A>::node *left = singly_linked_list<A>::mergesort(head);
    typename linkedlist<A>::node *right = singly_linked_list<A>::mergesort(next_of_middle);

    return singly_linked_list<A>::merge(left, right);
}

/**
 * @brief Merges two sorted linked lists into one sorted list.
 *
 * @param left The head of the first sorted list.
 * @param right The head of the second sorted list.
 * @return The head of the merged sorted list.
 */
template <typename A>
typename linkedlist<A>::node *singly_linked_list<A>::merge(typename linkedlist<A>::node *left, typename linkedlist<A>::node *right)
{
    if (left == nullptr)
        return right;
    
    if (right == nullptr)
        return left;

    if (left->value <= right->value) 
    {
        left->next = singly_linked_list<A>::merge(left->next, right);
        return left;
    }

    right->next = singly_linked_list<A>::merge(left, right->next);
    return right;
}

/**
 * @brief Copies the contents of another linked list into this list.
 *
 * This method replaces the current list with a copy of the provided linked list.
 *
 * @param obj The linked list to be copied.
 * @return A reference to this singly linked list.
 */
template <typename A>
singly_linked_list<A> &singly_linked_list<A>::copy(const singly_linked_list<A> &obj) 
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

/**
 * @brief Accesses the value at a specific index in the singly linked list.
 *
 * This method returns a reference to the value at the specified index. Negative indices count from the end.
 *
 * @param index The index of the value to be accessed.
 * @return A reference to the value at the specified index.
 * @throws INDEX_ERROR If the list is empty or the index is out of range.
 */
template <typename A>
A &singly_linked_list<A>::operator[](const int64_t &index)
{
    if (this->isempty())
        throw INDEX_ERROR("Indexing an Empty List");

    if (index < -(int64_t)(this->size()) || index >= (int64_t)(this->size()))
        throw INDEX_ERROR("List index out of range");

    if (index == 0L || index == -(int64_t)(this->size()))
        return this->head->value;

    int64_t curr_index = 0L;
    if (index < 0L)
        curr_index = -(int64_t)(this->size());

    typename linkedlist<A>::node *ptr = this->head;
    while (curr_index != index)
    {
        ptr = ptr->next;
        curr_index++;
    }

    return ptr->value;
}

/**
 * @brief Concatenates two linked lists into a new singly linked list.
 *
 * This method creates a new list that is the result of concatenating the current list with the provided list.
 *
 * @param obj The linked list to be concatenated.
 * @return A new singly linked list containing the concatenated result.
 */
template <typename A>
singly_linked_list<A> singly_linked_list<A>::operator+(const linkedlist<A> &obj)
{
    singly_linked_list<A> list_obj = *this;
    list_obj.extend(obj);

    return list_obj;
}

/**
 * @brief Repeats the singly linked list a specified number of times.
 *
 * This method creates a new list that repeats the current list the specified number of times.
 *
 * @param times The number of times to repeat the list.
 * @return A new singly linked list containing the repeated list.
 */
template <typename A>
singly_linked_list<A> singly_linked_list<A>::operator*(const size_t &times) 
{
    singly_linked_list<A> list_obj = *this;
    for (size_t i = times - 1; i != 0; i--)
        list_obj.extend(*this);

    return list_obj;
}

/**
 * @brief Checks if the current list is greater than the provided list.
 *
 * This method compares the current list with the provided list element-wise.
 *
 * @param obj The linked list to compare with.
 * @return True if the current list is greater than the provided list, otherwise false.
 */
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

/**
 * @brief Checks if the current list is less than the provided list.
 *
 * This method compares the current list with the provided list element-wise.
 *
 * @param obj The linked list to compare with.
 * @return True if the current list is less than the provided list, otherwise false.
 */
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

/**
 * @brief Checks if the current list is greater than or equal to the provided list.
 *
 * This method compares the current list with the provided list element-wise.
 *
 * @param obj The linked list to compare with.
 * @return True if the current list is greater than or equal to the provided list, otherwise false.
 */
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

/**
 * @brief Checks if the current list is less than or equal to the provided list.
 *
 * This method compares the current list with the provided list element-wise.
 *
 * @param obj The linked list to compare with.
 * @return True if the current list is less than or equal to the provided list, otherwise false.
 */
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

/**
 * @brief Checks if the current list is equal to the provided list.
 *
 * This method compares the current list with the provided list element-wise.
 *
 * @param obj The linked list to compare with.
 * @return True if the current list is equal to the provided list, otherwise false.
 */
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

/**
 * @brief Checks if the current list is not equal to the provided list.
 *
 * This method compares the current list with the provided list element-wise.
 *
 * @param obj The linked list to compare with.
 * @return True if the current list is not equal to the provided list, otherwise false.
 */
template <typename A>
bool singly_linked_list<A>::operator!=(const linkedlist<A> &obj) const
{
    return !(*this == obj);
}

/**
 * @brief Displays the singly linked list.
 *
 * This method prints the list to the standard output using the `<<` operator.
 */
template <typename A>
void singly_linked_list<A>::show() const
{
    std::cout << *this;
}

/**
 * @brief Clears the singly linked list.
 *
 * This method removes all elements from the list and releases allocated memory.
 */
template <typename A>
void singly_linked_list<A>::clear() 
{
    while (!this->isempty())
    {
        typename linkedlist<A>::node *temp = this->head;
        this->head = this->head->next;
        delete temp;

        temp = nullptr;
    }

    this->tail = nullptr;
    this->length = 0;
}

/**
 * @brief Repeats a singly linked list a specified number of times.
 *
 * This function creates a new list by repeating the provided list the specified number of times.
 *
 * @param times The number of times to repeat the list.
 * @param obj The singly linked list to be repeated.
 * @return A new singly linked list containing the repeated list.
 */
template <typename A>
singly_linked_list<A> operator*(const size_t &times, singly_linked_list<A> &obj)
{
    return obj * times;
}

/**
 * @brief Outputs the singly linked list to an output stream.
 *
 * This function allows the list to be printed using the `<<` operator.
 *
 * @param out The output stream to which the list will be written.
 * @param obj The singly linked list to be printed.
 * @return The output stream with the list data.
 */
template <typename A>
std::ostream &operator<<(std::ostream &out, singly_linked_list<A> &obj)
{    
    out << "[";

    if (obj.isempty())
    {
        out << "]";
        return out;
    }

    typename linkedlist<A>::node *ptr = linkedlist<A>::gethead(obj);
    while (ptr != linkedlist<A>::gettail(obj))
    {
        out << ptr->value << ", ";
        ptr = ptr->next;
    }

    out << ptr->value << "]";

    return out;
}

/**
 * @brief Destructor for singly linked list.
 *
 * This method clears the list and releases allocated memory.
 */
template <typename A>
singly_linked_list<A>::~singly_linked_list() 
{
    this->clear();
}
