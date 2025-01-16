#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>

#include "queue_linkedlist.h"
#include "stack_linkedlist.h"

using namespace std;

struct Person {
  string name;
  int time_arrived;
  int time_requested;
};

template <typename T, typename = enable_if<is_same_v<T, Stack<Person>> ||
                                           is_same_v<T, Queue<Person>>>>
T* process(std::ifstream& f) {
  return new T;
}

int main() {
  ifstream f;
  f.open("personin.txt");
  process<Stack<Person>>(f);

  f.seekg(0);
  f.clear();
  process<Queue<Person>>(f);

  f.close();
}
