#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>

#include "queue_linkedlist.h"
#include "stack_linkedlist.h"

using namespace std;

/**
 * @struct Person
 * @brief Represents an individual with their name, arrival time, and time
 * requested for processing.
 *
 * This structure holds the necessary details about a person, including:
 * - `name`: The person's name (as a string).
 * - `time_arrived`: The time the person arrived, represented as an integer
 * (e.g., in minutes).
 * - `time_requested`: The amount of time the person requested for their task,
 * also as an integer.
 */
struct Person {
  string name;
  int time_arrived;
  int time_requested;
};

/**
 * @brief Reinserts an item to the front of the stack.
 *
 * This function duplicates the current stack's items, pushes the new item
 * to the top, and then pushes all other items back in their original order.
 *
 * @param stack The stack to modify.
 * @param item The item to insert at the top of the stack.
 */
template <typename T>
void reinstateFront(T* container, Person item) {
  if constexpr (is_same_v<T, Stack<Person>>) {
    Stack<Person> tmp;
    while (!container->isEmpty()) {
      tmp.push(container->pop());
    }
    container->push(item);
    while (!tmp.isEmpty()) {
      container->push(tmp.pop());
    }
  }
}

/**
 * @brief Processes a file to create and manage a queue or stack of `Person`
 * objects, displaying the schedule in which people arrive and are met with.
 *
 * @tparam T The container type (either `Stack<Person>` or `Queue<Person>`).
 * @tparam typename S A type trait constraint to ensure the function is only
 * instantiated for `Stack` or `Queue` of `Person` objects.
 *
 * @param f The input file stream to read the person data from.
 * @return A pointer to an instance of the container `T` (either `Stack<Person>`
 * or `Queue<Person>`).
 */
template <typename T, typename = enable_if_t<is_same_v<T, Stack<Person>> ||
                                             is_same_v<T, Queue<Person>>>>
void process(ifstream& f) {
  int current_time = 0;    // Track the current time for meetings
  auto container = new T;  // Stack or Queue to hold the people
  Person p, next;

  f >> p.name >> p.time_arrived >> p.time_requested;
  cout << (is_same_v<T, Stack<Person>>
               ? "-=-=-=-=-=-=-=-=- Unfair Way -=-=-=-=-=-=-=-=-"
               : "\n-=-=-=-=-=-=-=-=- Fair Way -=-=-=-=-=-=-=-=-")
       << endl;
  cout << p.name << " arrives at " << p.time_arrived
       << " and requests a meeting length of " << p.time_requested << "\n";

  if (current_time < p.time_arrived) {
    current_time = p.time_arrived;
  }
  cout << p.name << " meets from " << current_time << " to "
       << current_time + p.time_requested << "\n";
  current_time += p.time_requested;

  while (f >> next.name >> next.time_arrived >> next.time_requested) {
    while (next.time_arrived <= current_time) {
      cout << next.name << " arrives at " << next.time_arrived
           << " and requests a meeting length of " << next.time_requested
           << "\n";
      if constexpr (is_same_v<T, Stack<Person>>) {
        container->push(next);
      } else if constexpr (is_same_v<T, Queue<Person>>) {
        container->enqueue(next);
      }

      // Continue reading the next person if arrival time <= current_time
      if (!(f >> next.name >> next.time_arrived >> next.time_requested)) {
        break;
      }
    }

    while (!container->isEmpty()) {
      Person next_in_line;
      if constexpr (is_same_v<T, Stack<Person>>) {
        next_in_line =
            container->pop();  // Get the next person from stack (LIFO)
      } else if constexpr (is_same_v<T, Queue<Person>>) {
        next_in_line =
            container->dequeue();  // Get the next person from queue (FIFO)
      }

      if (next.time_arrived <= current_time && is_same_v<T, Stack<Person>>) {
        // Process the new arrival immediately
        cout << next.name << " arrives at " << next.time_arrived
             << " and requests a meeting length of " << next.time_requested
             << "\n";
        if (current_time < next.time_arrived) {
          current_time = next.time_arrived;  // Adjust time if professor is idle
        }
        cout << next.name << " meets from " << current_time << " to "
             << current_time + next.time_requested << "\n";
        current_time += next.time_requested;

        // After processing the new arrival, break out and continue reading for
        // other new arrivals
        reinstateFront(container, next_in_line);
        break;
      }

      if (current_time < next_in_line.time_arrived) {
        current_time =
            next_in_line.time_arrived;  // Adjust time if the professor is idle
      }
      cout << next_in_line.name << " meets from " << current_time << " to "
           << current_time + next_in_line.time_requested << "\n";
      current_time += next_in_line.time_requested;
    }

    if (container->isEmpty()) {
      if (current_time < next.time_arrived) {
        current_time = next.time_arrived;
      }
      cout << next.name << " arrives at " << next.time_arrived
           << " and requests a meeting length of " << next.time_requested
           << "\n";
      cout << next.name << " meets from " << current_time << " to "
           << current_time + next.time_requested << "\n";
      current_time += next.time_requested;
    }
  }
}

int main() {
  ifstream f;
  f.open("personin.txt");

  process<Stack<Person>>(f);

  f.clear();
  f.seekg(0, ios::beg);

  process<Queue<Person>>(f);

  f.close();
}
