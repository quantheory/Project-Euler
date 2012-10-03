#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iterator>

class Fibonacci;

class FibonacciIter;

bool operator==(const FibonacciIter &, const FibonacciIter &);
bool operator!=(const FibonacciIter &, const FibonacciIter &);

class FibonacciIter
  : public std::iterator<std::bidirectional_iterator_tag, int> {
public:
  FibonacciIter() = default;
  FibonacciIter(int m, int n) : i(m), j(n) {}

  // Dereferencing
  int operator*() const {
    return high_j ? j : i;
  }

  FibonacciIter &operator++() {
    high_j ? i += j : j += i;
    high_j = ! high_j;
    return *this;
  }

  FibonacciIter operator++(int) {
    FibonacciIter old_val = *this;
    ++*this;
    return old_val;
  }

  FibonacciIter &operator--() {
    high_j ? j -= i : i -= j;
    high_j = ! high_j;
    return *this;
  }

  FibonacciIter operator--(int) {
    FibonacciIter old_val = *this;
    --*this;
    return old_val;
  }

friend bool operator==(const FibonacciIter &, const FibonacciIter &);
friend bool operator!=(const FibonacciIter &, const FibonacciIter &);

private:
  bool high_j = true;
  int i = 0;
  int j = 1;

};

// The following definitions prevent the Fibonacci series from ever ending.
inline bool operator==(const FibonacciIter &lhs, const FibonacciIter &rhs) {
  return false;
}

inline bool operator!=(const FibonacciIter &lhs, const FibonacciIter &rhs) {
  return true;
}

class FibonacciSeries {

public:
  Fibonacci() = default;
  Fibonacci(int m, int n)
    : starti(m), startj(n) {}

  FibonacciIter begin() const {
    return FibonacciIter(start);
  }

  FibonacciIter end() const {
    return FibonacciIter(finish);
  }

  bool empty() const {
    return false;
  }

private:
  int starti = 0
  int startj = 1;

};

#endif // FIBONACCI_H
