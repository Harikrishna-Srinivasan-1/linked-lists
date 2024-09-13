#include "linkedlist.h"

/**
 * @brief Default constructor for the linkedlist class.
 * 
 * Initializes an empty linked list with both head and tail pointers set to nullptr.
 */
template <typename A>
linkedlist<A>::linkedlist() : head(nullptr), tail(nullptr) {}

/**
 * @brief Gets the head pointer of the linked list.
 * 
 * This static method provides access to the head node of the specified linked list.
 * 
 * @param obj The linked list whose head node is to be retrieved.
 * @return A pointer to the head node of the linked list.
 */
template <typename A>
typename linkedlist<A>::node *linkedlist<A>::gethead(const linkedlist<A> &obj) 
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
typename linkedlist<A>::node* linkedlist<A>::getmiddle(linkedlist<A>::node *head) {
    // If the list is empty, return nullptr
    if (head == nullptr)
        return head;

    node *fast = head;  ///< Pointer that moves two steps at a time
    node *slow = head;  ///< Pointer that moves one step at a time

    // Traverse the list with fast and slow pointers
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
typename linkedlist<A>::node *linkedlist<A>::gettail(const linkedlist<A> &obj) 
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
size_t linkedlist<A>::size() const
{
    return len(*this);
}

/**
 * @brief Checks if the linked list is empty.
 * 
 * This method determines if the linked list contains no elements by checking if the head pointer is nullptr.
 * 
 * @return True if the linked list is empty; otherwise, false.
 */
template <typename A>
bool linkedlist<A>::isempty() const
{
    return (this->head == nullptr);
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
    typename linkedlist<A>::node *ptr = obj.head; ///< Pointer to traverse the linked list

    // Traverse the linked list and count nodes
    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }

    return size;
}
