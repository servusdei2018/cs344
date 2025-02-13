#include "unionfind.h"

#include <iostream>
#include <numeric>

using namespace std;

/**
 * @brief Constructs a UnionFind object with `n` elements.
 *
 * This constructor initializes the parent of each element to itself and the
 * size of each tree to 1.
 *
 * @param n The number of elements in the Union-Find structure.
 */
UnionFind::UnionFind(int n) {
  parent.resize(n);
  size.resize(n, 1);
  iota(parent.begin(), parent.end(), 0);
}

/**
 * @brief Unites the sets containing elements `x` and `y`.
 *
 * This function performs a union operation, combining the sets containing `x`
 * and `y`. If the sets are already connected, this operation does nothing.
 *
 * @param x The first element to unite.
 * @param y The second element to unite.
 */
void UnionFind::unionSets(int x, int y) {
  int rX = find(x);
  int rY = find(y);

  if (rX != rY) {
    if (size[rX] < size[rY]) {
      parent[rX] = rY;
      size[rY] += size[rX];
    } else {
      parent[rY] = rX;
      size[rX] += size[rY];
    }
  }
}

/**
 * @brief Prints the current state of the Union-Find structure.
 */
void UnionFind::print() {
  cout << "[ ";
  for (auto elem : parent) cout << elem << " ";
  cout << "]\n";
}

UnionFindWeighted::UnionFindWeighted(int n) : UnionFind(n) {}

/**
 * @brief Finds the root of the set containing element `x`.
 *
 * @param x The element whose root is to be found.
 * @return The root of the set containing `x`.
 */
int UnionFindWeighted::find(int x) {
  while (x != parent[x]) {
    x = parent[x];
  }
  return x;
}

UnionFindCompressed::UnionFindCompressed(int n) : UnionFind(n) {}

/**
 * @brief Finds the root of the set containing element `x` (with path
 * compression).
 *
 * This function implements the find operation with path compression. It
 * flattens the structure by making each node point directly to the root,
 * speeding up future find operations.
 *
 * @param x The element whose root is to be found.
 * @return The root of the set containing `x`.
 */
int UnionFindCompressed::find(int x) {
  if (x != parent[x]) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}
