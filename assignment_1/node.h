// node.h
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename Item>
struct Node {
  Item item;
  Node<Item> *next;
};

#endif  // NODE_H_INCLUDED
