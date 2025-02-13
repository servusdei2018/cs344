#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

/**
 * @brief Base class for Union-Find data structure.
 */
class UnionFind {
 protected:
  std::vector<int> parent;  ///< The parent of each element.
  std::vector<int>
      size;  ///< The size of each tree in the Union-Find structure.

 public:
  UnionFind(int n);

  virtual int find(int x) = 0;
  void unionSets(int x, int y);
  void print();
};

class UnionFindWeighted : public UnionFind {
 public:
  UnionFindWeighted(int n);

  int find(int x) override;
};

class UnionFindCompressed : public UnionFind {
 public:
  UnionFindCompressed(int n);

  int find(int x) override;
};

#endif  // UNIONFIND_H
