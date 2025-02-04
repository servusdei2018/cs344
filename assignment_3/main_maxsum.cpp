#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

#include "maxsum.h"
using namespace std;
using namespace std::chrono;

float run_function(string funcname, int num_num) {
  auto start = high_resolution_clock::now();
  auto stop = high_resolution_clock::now();

  unsigned seed = system_clock::now().time_since_epoch().count();
  uniform_int_distribution<int> u(-100, 100);
  // uniform_int_distribution<int> u(0, INT_MAX-1);
  default_random_engine e(seed);  // generates unsigned random integers

  int *A = new int[num_num];
  for (int i = 0; i < num_num; i++) A[i] = u(e);

  if (funcname == "slow") {
    start = high_resolution_clock::now();
    maxsum_slow(A, num_num);
    stop = high_resolution_clock::now();
  } else if (funcname == "fast") {
    start = high_resolution_clock::now();
    maxsum_fast(A, 0, num_num - 1);
    stop = high_resolution_clock::now();
  } else if (funcname == "answer") {
    start = high_resolution_clock::now();
    print_array(A, num_num);
    cout << "Slow: " << endl;
    maxsum_slow(A, num_num).print();
    cout << "Fast: " << endl;
    maxsum_fast(A, 0, num_num - 1).print();
    stop = high_resolution_clock::now();
  } else {
    cout << "No such function " << endl;
    return -1;
  }

  delete[] A;
  auto duration = duration_cast<microseconds>(stop - start);
  float dur = duration.count();
  return dur;
}

int main() {
  int num_iter;     // Number of iterations
  int num_num;      // Number of numbers in array
  string funcname;  // Which function the user wants to run
  float dur, old_dur = 1, ratio;
  cout << "How many iterations? ";
  cin >> num_iter;
  cout << "How many numbers to start with? ";
  cin >> num_num;
  cout << "Which function are you running? ";
  cin >> funcname;

  for (int i = 0; i < num_iter; i++) {
    dur = run_function(funcname, num_num);
    if (dur == -1) return 0;
    ratio = dur / old_dur;
    cout << "Size: " << num_num << ", "
         << "Time: " << dur / 1000000 << ",  "
         << "Ratio: " << ratio << endl;
    old_dur = dur;
    num_num = 2 * num_num;
  }
  return 0;
}
