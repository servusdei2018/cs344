// stack_linkedlist.h
#ifndef STACK_LINKEDLIST_H_INCLUDED
#define STACK_LINKEDLIST_H_INCLUDED

#include <cstddef>

#include "node.h"

/**
 * @class Stack
 * @brief A stack implementation using a linked list.
 *
 * This class represents a stack data structure where elements are added and
 * removed from the top of the stack, following the Last-In-First-Out (LIFO)
 * order. The underlying implementation uses a linked list to dynamically
 * allocate memory.
 *
 * @tparam Item The type of elements stored in the stack.
 *
 * The following operations are supported:
 * - **push(item)**: Adds the specified item to the top of the stack.
 * - **pop()**: Removes and returns the item from the top of the stack.
 * - **size()**: Returns the current number of items in the stack.
 * - **isEmpty()**: Checks if the stack is empty.
 */

template <typename Item>
class Stack {
 private:
  struct Node<Item>
      *first;  ///< Pointer to the top of the stack (most recently added item).
  int N;       ///< The number of items currently in the stack.

 public:
  Stack() : first(NULL), N(0) {}
  ~Stack();
  bool isEmpty() { return first == NULL; }
  int size() { return N; }
  void push(Item item);
  Item pop();
};

/**
 * @brief Adds an item to the top of the stack.
 *
 * This function creates a new node with the given item and places it at the top
 * of the stack. The new node points to the current top of the stack, making the
 * new item the most recent.
 *
 * @param item The item to add to the stack.
 */
template <typename Item>
void Stack<Item>::push(Item item) {
  Node<Item> *oldfirst = first;
  first = new Node<Item>;
  first->item = item;
  first->next = oldfirst;
  N++;
}

/**
 * @brief Removes and returns the item from the top of the stack.
 *
 * This function removes the top item from the stack and returns it. The next
 * item in the stack becomes the new top item.
 *
 * @return The item removed from the top of the stack.
 */
template <typename Item>
Item Stack<Item>::pop() {
  Node<Item> *oldfirst = first;
  Item item = first->item;
  first = first->next;
  delete oldfirst;
  N--;
  return item;
}

/**
 * @brief Destructor for the Stack class.
 *
 * This function deallocates memory for all nodes in the stack.
 */
template <typename Item>
Stack<Item>::~Stack() {
  while (first != NULL) {
    Node<Item> *p = first->next;
    delete first;
    first = p;
  }
}

#endif  // STACK_LINKEDLIST_H_INCLUDED
