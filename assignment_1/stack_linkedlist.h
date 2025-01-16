// stack_linkedlist.h
#ifndef STACK_LINKEDLIST_H_INCLUDED
#define STACK_LINKEDLIST_H_INCLUDED

#include <cstddef>

#include "node.h"

/*
Stack functions:
push(item): pushes the item on the stack.
pop(): returns the top item of the stack and deletes it from the stack.
size(): returns the size of the stack.
isEmpty(): checks whether the stack is empty or not.
*/

template <typename Item>
class Stack {
 private:
  struct Node<Item> *first;  // top of stack (most recently added item)
  int N;                     // number of items

 public:
  Stack() : first(NULL), N(0) {}
  ~Stack();
  bool isEmpty() { return first == NULL; }
  int size() { return N; }
  void push(Item item);
  Item pop();
};

template <typename Item>
void Stack<Item>::push(Item item) {
  // Add item to top of stack
  Node<Item> *oldfirst = first;
  first = new Node<Item>;
  first->item = item;
  first->next = oldfirst;
  N++;
}

template <typename Item>
Item Stack<Item>::pop() {
  // Remove item from stack and return it
  Node<Item> *oldfirst = first;
  Item item = first->item;
  first = first->next;
  delete oldfirst;
  N--;
  return item;
}

template <typename Item>
Stack<Item>::~Stack() {
  while (first != NULL) {
    Node<Item> *p = first->next;
    delete first;
    first = p;
  }
}

#endif  // STACK_LINKEDLIST_H_INCLUDED
