#include "linkedlist.hpp"


/**
 * @brief Constructor for the const_iterator.
 * 
 * Initializes the const_iterator with the pointer to nullptr.
 * 
 * @param ptr A pointer to the node the const_iterator will point to.
 */
template <typename A>
linkedlist<A>::const_iterator::const_iterator():
    ptr(nullptr) {}

/**
 * @brief Constructor for the const_iterator.
 * 
 * Initializes the const_iterator with the pointer to a node in the linked list.
 * 
 * @param ptr A pointer to the node the const_iterator will point to.
 */
template <typename A>
linkedlist<A>::const_iterator::const_iterator(typename linkedlist<A>::node *ptr):
    ptr(ptr) {}

/**
 * @brief Prefix increment operator for the const_iterator.
 * 
 * Advances the const_iterator to the next element in the linked list.
 * 
 * @return linkedlist<A>::const_iterator& A reference to the updated const_iterator.
 */
template <typename A>
constexpr const typename linkedlist<A>::const_iterator &linkedlist<A>::const_iterator::operator++()
{
    this->ptr = this->ptr->next;
    
    return *this;
}

/**
 * @brief Postfix increment operator for the const_iterator.
 * 
 * Advances the const_iterator to the next element in the linked list.
 * 
 * @param int Dummy parameter to distinguish from the prefix increment.
 * @return linkedlist<A>::const_iterator& A reference to the const_iterator before incrementing.
 */
template <typename A>
constexpr const typename linkedlist<A>::const_iterator &linkedlist<A>::const_iterator::operator++(int)
{
    this->ptr = this->ptr->next;

    return *this;
}

/**
 * @brief Dereference operator for the const_iterator.
 * 
 * This operator returns the value pointed to by the const_iterator.
 * 
 * @return A The value of type A that the const_iterator points to.
 */
template <typename A>
constexpr const A &linkedlist<A>::const_iterator::operator*() const
{
    return this->ptr->value;
}

/**
 * @brief Equality operator for the const_iterator.
 * 
 * Compares two const_iterators for equality by checking if they point to the same node.
 * 
 * @param it The const_iterator to compare against.
 * @return true If both const_iterators point to the same node, false otherwise
 */
template <typename A>
constexpr bool linkedlist<A>::const_iterator::operator==(const typename linkedlist<A>::const_iterator &it) const
{
    return this->ptr == it.ptr;
}

/**
 * @brief Inequality operator for the const_iterator.
 * 
 * Compares two const_iterators for inequality by checking if they point to different nodes.
 * 
 * @param it The const_iterator to compare against.
 * @return true If both const_iterators point to different nodes, false otherwise
 */
template <typename A>
constexpr bool linkedlist<A>::const_iterator::operator!=(const typename linkedlist<A>::const_iterator &it) const
{
    return this->ptr != it.ptr;
}

/**
 * @brief Constructor for the iterator.
 * 
 * Initializes the iterator with the pointer to nullptr.
 * 
 * @param ptr A pointer to the node the iterator will point to.
 */
template <typename A>
linkedlist<A>::iterator::iterator():
    ptr(nullptr) {}

/**
 * @brief Constructor for the iterator.
 * 
 * Initializes the iterator with the pointer to a node in the linked list.
 * 
 * @param ptr A pointer to the node the iterator will point to.
 */
template <typename A>
linkedlist<A>::iterator::iterator(typename linkedlist<A>::node *ptr):
    ptr(ptr) {}

/**
 * @brief Default constructor for the linkedlist class.
 * 
 * Initializes an empty linked list with both head and tail pointers set to nullptr.
 */
template <typename A>
linkedlist<A>::linkedlist():
    head(new linkedlist<A>::node*(nullptr)), tail(new linkedlist<A>::node*(nullptr)) {}

/**
 * @brief Prefix increment operator for the iterator.
 * 
 * Advances the iterator to the next element in the linked list.
 * 
 * @return linkedlist<A>::iterator& A reference to the updated iterator.
 */
template <typename A>
constexpr typename linkedlist<A>::iterator &linkedlist<A>::iterator::operator++()
{
    this->ptr = this->ptr->next;
    
    return *this;
}

/**
 * @brief Postfix increment operator for the iterator.
 * 
 * Advances the iterator to the next element in the linked list.
 * 
 * @param int Dummy parameter to distinguish from the prefix increment.
 * @return linkedlist<A>::iterator& A reference to the iterator before incrementing.
 */
template <typename A>
constexpr typename linkedlist<A>::iterator &linkedlist<A>::iterator::operator++(int)
{
    this->ptr = this->ptr->next;

    return *this;
}

/**
 * @brief Dereference operator for the iterator.
 * 
 * This operator returns the value pointed to by the iterator.
 * 
 * @return A The value of type A that the iterator points to.
 */
template <typename A>
constexpr A &linkedlist<A>::iterator::operator*()
{
    return this->ptr->value;
}

/**
 * @brief Equality operator for the iterator.
 * 
 * Compares two iterators for equality by checking if they point to the same node.
 * 
 * @param it The iterator to compare against.
 * @return true If both iterators point to the same node, false otherwise
 */
template <typename A>
constexpr bool linkedlist<A>::iterator::operator==(const typename linkedlist<A>::iterator &it) const
{
    return this->ptr == it.ptr;
}

/**
 * @brief Inequality operator for the iterator.
 * 
 * Compares two iterators for inequality by checking if they point to different nodes.
 * 
 * @param it The iterator to compare against.
 * @return true If both iterators point to different nodes, false otherwise
 */
template <typename A>
constexpr bool linkedlist<A>::iterator::operator!=(const typename linkedlist<A>::iterator &it) const
{
    return this->ptr != it.ptr;
}

/**
 * @brief Gets the head pointer of the linked list.
 * 
 * This static method provides access to the head node of the specified linked list.
 * 
 * @param obj The linked list whose head node is to be retrieved.
 * @return A pointer to the head node of the linked list.
 */
template <typename A>
constexpr typename linkedlist<A>::node **linkedlist<A>::gethead(const linkedlist<A> &obj) 
{
    return obj.head;
}

/**
 * @brief Finds the middle node of the linked list.
 * 
 * This static method uses the slow and fast pointer technique to find the middle node
 * of the linked list starting from the given head node. If the list has an even number
 * of nodes, it returns the node just before the exact middle.
 * 
 * @param head The head node of the linked list to find the middle of.
 * @return A pointer to the middle node of the linked list.
 */
template <typename A>
constexpr typename linkedlist<A>::node *linkedlist<A>::getmiddle(linkedlist<A>::node *head) 
{
    if (head == nullptr)
        return head;

    node *fast = head, *slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/**
 * @brief Gets the tail pointer of the linked list.
 * 
 * This static method provides access to the tail node of the specified linked list.
 * 
 * @param obj The linked list whose tail node is to be retrieved.
 * @return A pointer to the tail node of the linked list.
 */
template <typename A>
constexpr typename linkedlist<A>::node **linkedlist<A>::gettail(const linkedlist<A> &obj) 
{
    return obj.tail;
}

/**
 * @brief Returns the number of elements in the linked list.
 * 
 * This method computes the size of the linked list by calling the len function.
 * 
 * @return The number of elements in the linked list.
 */
template <typename A>
constexpr size_t linkedlist<A>::size() const
{
    return len(*this);
}

/**
 * @brief Checks if the linked list is empty.
 * 
 * This method determines if the linked list contains no elements by checking if the head pointer is nullptr.
 * 
 * @return true if the linked list is empty, false otherwise.
 */
template <typename A>
constexpr bool linkedlist<A>::isempty() const
{
    return (*this->head == nullptr);
}

/**
 * @brief Get an const_iterator to the beginning of the linked list.
 * 
 * This function returns an const_iterator pointing to the first element in the linked list.
 * 
 * @return linkedlist<A>::const_iterator An const_iterator to the beginning of the list.
 */
template <typename A>
constexpr typename linkedlist<A>::iterator linkedlist<A>::begin()
{
    return linkedlist<A>::iterator(*this->head);
}

/**
 * @brief Get an const_iterator to the end of the linked list.
 * 
 * This function returns an const_iterator pointing to the end (one past the last element) of the linked list.
 * 
 * @return linkedlist<A>::const_iterator An const_iterator to the end of the list.
 */
template <typename A>
constexpr typename linkedlist<A>::iterator linkedlist<A>::end()
{
    return linkedlist<A>::iterator(nullptr);
}

/**
 * @brief Get a const const_iterator to the beginning of the linked list.
 * 
 * This function returns a const const_iterator pointing to the first element in the linked list.
 * 
 * @return const linkedlist<A>::const_iterator A const const_iterator to the beginning of the list.
 */
template <typename A>
constexpr const typename linkedlist<A>::const_iterator linkedlist<A>::cbegin() const
{
    return linkedlist<A>::const_iterator(*this->head);
}

/**
 * @brief Get a const const_iterator to the end of the linked list.
 * 
 * This function returns a const const_iterator pointing to the end (one past the last element) of the linked list.
 * 
 * @return const linkedlist<A>::const_iterator A const const_iterator to the end of the list.
 */
template <typename A>
constexpr const typename linkedlist<A>::const_iterator linkedlist<A>::cend() const
{
    return linkedlist<A>::const_iterator(nullptr);
}

/**
 * @brief Finds and returns the minimum value in the singly linked list.
 *
 * An exception is thrown if the list is empty.
 *
 * @param obj The linked list object to search for the minimum value.
 * @return The minimum value in the list.
 * @throws VALUE_ERROR If the list is empty.
 */
template <typename A>
A min(const linkedlist<A> &obj)
{
    if (obj.isempty())
        throw VALUE_ERROR("Finding min in Empty List");

    A min_value = (*obj.head)->value;
    typename linkedlist<A>::node *ptr = (*obj.head)->next;
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
 * An exception is thrown if the list is empty.
 *
 * @param obj The linked list object to search for the maximum value.
 * @return The maximum value in the list.
 * @throws VALUE_ERROR If the list is empty.
 */
template <typename A>
A max(const linkedlist<A> &obj)
{
    if (obj.isempty())
        throw VALUE_ERROR("Finding max in Empty List");

    A max_value = (*obj.head)->value;
    typename linkedlist<A>::node *ptr = (*obj.head)->next;
    while (ptr != nullptr)
    {
        if (ptr->value > max_value)
            max_value = ptr->value;
        ptr = ptr->next;
    }

    return max_value;
}

/**
 * @brief Calculates the length of the linked list.
 * 
 * This function iterates through the linked list from the head node and counts the number of nodes.
 * 
 * @param obj The linked list whose length is to be calculated.
 * @return The number of nodes in the linked list.
 */
template <typename A>
size_t len(const linkedlist<A> &obj)
{
    size_t size = 0; ///< Variable to keep track of the number of nodes
    typename linkedlist<A>::node *ptr = *obj.head; ///< Pointer to traverse the linked list

    // Traverse the linked list and count nodes
    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }

    return size;
}
