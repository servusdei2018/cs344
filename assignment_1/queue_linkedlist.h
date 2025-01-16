#ifndef QUEUE_LINKEDLIST_H_INCLUDED
#define QUEUE_LINKEDLIST_H_INCLUDED

#include <cstddef>

#include "node.h"

/*
Queue functions:
enqueue(item): adds the item to the back of the queue.
dequeue(): returns the first element of the queue and deletes it from the queue.
size(): returns the size of the queue.
isEmpty(): checks whether the queue is empty or not.
*/

template <typename Item>
class Queue {
 private:
  struct Node<Item> *first;  // link to least recently added node
  struct Node<Item> *last;   // link to most recently added node
  int n;                     // number of items on the queue

 public:
  Queue() : first(NULL), last(NULL), n(0) {}
  ~Queue();
  bool isEmpty() { return first == NULL; }
  int size() { return n; }
  void enqueue(Item item);
  Item dequeue();
};

template <typename Item>
void Queue<Item>::enqueue(Item item) {
  // Add item to the end of the list.
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

template <typename Item>
Item Queue<Item>::dequeue() {
  // Remove item from the beginning of the list
  Item item = first->item;
  Node<Item> *oldfirst = first;
  first = first->next;
  n--;
  if (isEmpty()) last = NULL;
  delete oldfirst;
  return item;
}

template <typename Item>
Queue<Item>::~Queue() {
  while (first != NULL) {
    Node<Item> *p = first->next;
    delete first;
    first = p;
  }
}

#endif  // QUEUE_LINKEDLIST_H_INCLUDED
