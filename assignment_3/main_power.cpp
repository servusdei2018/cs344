#include <iostream>

#include "power.h"
using namespace std;

int main() {
  long double x;
  int n;
  string version;
  cout << "What is the base? ";
  cin >> x;
  cout << "What is the exponent? ";
  cin >> n;
  cout << power_iter(x, n) << endl;
  cout << power_rec(x, n) << endl;
  cout << power_half(x, n) << endl;

  return 0;
}
