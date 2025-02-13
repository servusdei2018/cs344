#include <iostream>
#include <vector>

#include "unionfind.h"

using namespace std;

int main() {
  vector<pair<int, int>> unions = {{0, 1}, {7, 6},   {8, 9},  {3, 2},
                                   {1, 3}, {12, 5},  {1, 5},  {4, 7},
                                   {4, 9}, {10, 11}, {11, 4}, {5, 11}};

  UnionFindWeighted ufw(13);
  for (const auto& [x, y] : unions) ufw.unionSets(x, y);
  cout << "UnionFindWeighted: ";
  ufw.print();

  UnionFindCompressed ufc(13);
  for (const auto& [x, y] : unions) ufc.unionSets(x, y);
  cout << "UnionFindCompressed: ";
  ufc.print();

  return 0;
}
