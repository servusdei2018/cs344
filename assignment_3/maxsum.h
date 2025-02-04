#ifndef MAXSUM_H_INCLUDED
#define MAXSUM_H_INCLUDED

#include <iostream>
using namespace std;

void print_array(int A[], int n);

struct sol {
  int lo, hi, sum;
  sol() { lo = hi = sum = 0; }
  sol(int l, int h, int s) { lo = l, hi = h, sum = s; }
  void print() {
    cout << "Low: " << lo << " High: " << hi << " Sum: " << sum << endl;
  }
};

struct maxsums {
  sol entire, begin, end, best;
  maxsums() {
    entire = sol();
    begin = sol();
    end = sol();
    best = sol();
  }
  maxsums(sol s1, sol s2, sol s3, sol s4) {
    entire = s1;
    begin = s2;
    end = s3;
    best = s4;
  }
  void print();
};

int sum_array(int A[], int lo, int hi);

sol maxsol(sol s1, sol s2);

sol concat(sol s1, sol s2);

maxsums maxsum_slow(int A[], int n);

maxsums maxsum_fast(int A[], int start, int stop);

#endif  // MAXSUM_H_INCLUDED
