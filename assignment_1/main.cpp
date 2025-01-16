#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>

#include "queue_linkedlist.h"
#include "stack_linkedlist.h"

using namespace std;

/**
 * @struct Person
 * @brief Represents an individual with their name, arrival time, and time requested for processing.
 * 
 * This structure holds the necessary details about a person, including:
 * - `name`: The person's name (as a string).
 * - `time_arrived`: The time the person arrived, represented as an integer (e.g., in minutes).
 * - `time_requested`: The amount of time the person requested for their task, also as an integer.
 */
struct Person {
  string name;
  int time_arrived;
  int time_requested;
};

/** 
 * @brief Processes a file to create and manage a queue or stack of `Person` objects.
 * 
 * @tparam T The container type (either `Stack<Person>` or `Queue<Person>`).
 * @tparam typename S A type trait constraint to ensure the function is only instantiated for `Stack`
 *                    or `Queue` of `Person` objects.
 * 
 * @param f The input file stream to read the person data from.
 * @return A pointer to an instance of the container `T` (either `Stack<Person>` or `Queue<Person>`).
 */
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
