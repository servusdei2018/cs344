#ifndef QUEUE_LINKEDLIST_H_INCLUDED
#define QUEUE_LINKEDLIST_H_INCLUDED

#include <cstddef>

#include "node.h"

/**
 * @class Queue
 * @brief A queue implementation using a linked list.
 *
 * This class represents a simple queue data structure where elements
 * are added to the back of the queue and removed from the front. The queue
 * follows a First-In-First-Out (FIFO) order. The underlying implementation
 * uses a linked list for dynamic memory allocation.
 *
 * @tparam Item The type of elements stored in the queue.
 *
 * The following operations are supported:
 * - **enqueue(item)**: Adds the specified item to the back of the queue.
 * - **dequeue()**: Removes and returns the item from the front of the queue.
 * - **size()**: Returns the number of items currently in the queue.
 * - **isEmpty()**: Checks if the queue is empty.
 */

template <typename Item>
class Queue {
 private:
  struct Node<Item>
      *first;  ///< Pointer to the front of the queue (least recently added).
  struct Node<Item>
      *last;  ///< Pointer to the back of the queue (most recently added).
  int n;      ///< The number of items currently in the queue.

 public:
  Queue() : first(NULL), last(NULL), n(0) {}
  ~Queue();
  bool isEmpty() { return first == NULL; }
  int size() { return n; }
  void enqueue(Item item);
  Item dequeue();
};

/**
 * @brief Adds an item to the back of the queue.
 *
 * This function creates a new node with the given item and adds it to the end
 * of the queue. If the queue is empty, the new node becomes both the first and
 * last node.
 *
 * @param item The item to add to the queue.
 */
template <typename Item>
void Queue<Item>::enqueue(Item item) {
  Node<Item> *oldlast = last;
  last = new Node<Item>;
  last->item = item;
  last->next = NULL;
  if (isEmpty())
    first = last;
  else
    oldlast->next = last;
  n++;
}

/**
 * @brief Removes and returns the item from the front of the queue.
 *
 * This function removes the first node of the queue and returns its item. If
 * the queue becomes empty after the operation, it sets the `last` pointer to
 * `NULL`.
 *
 * @return Item The item removed from the front of the queue.
 */
template <typename Item>
Item Queue<Item>::dequeue() {
  Item item = first->item;
  Node<Item> *oldfirst = first;
  first = first->next;
  n--;
  if (isEmpty()) last = NULL;
  delete oldfirst;
  return item;
}

/**
 * @brief Destructor for the Queue class.
 *
 * This function deallocates memory for all nodes in the stack.
 */
template <typename Item>
Queue<Item>::~Queue() {
  while (first != NULL) {
    Node<Item> *p = first->next;
    delete first;
    first = p;
  }
}

#endif  // QUEUE_LINKEDLIST_H_INCLUDED
