#ifndef RANGE_H
#define RANGE_H

#include <iterator>

class Range;

class RangeIter;

bool operator==(const RangeIter &, const RangeIter &);
bool operator!=(const RangeIter &, const RangeIter &);

class RangeIter
  : public std::iterator<std::bidirectional_iterator_tag, int> {

public:
  RangeIter() = default;

  // Dereferencing
  int operator*() const {
    return i;
  }

  RangeIter &operator++() {
    ++i;
    return *this;
  }

  RangeIter operator++(int) {
    RangeIter old_val = *this;
    ++*this;
    return old_val;
  }

  RangeIter &operator--() {
    --i;
    return *this;
  }

  RangeIter operator--(int) {
    RangeIter old_val = *this;
    --*this;
    return old_val;
  }

  friend bool operator==(const RangeIter &, const RangeIter &);
  friend bool operator!=(const RangeIter &, const RangeIter &);

private:
  int i = 0;
  RangeIter(int n) : i(n) {}

  friend class Range;

};

inline bool operator==(const RangeIter &lhs, const RangeIter &rhs) {
  return lhs.i == rhs.i;
}

inline bool operator!=(const RangeIter &lhs, const RangeIter &rhs) {
  return lhs.i != rhs.i;
}

class Range {

public:
  Range() = default;
  Range(int m, int n) : start(m), finish(n) {}

  RangeIter begin() const {
    return RangeIter(start);
  }

  RangeIter end() const {
    return RangeIter(finish);
  }

  bool empty() const {
    return start == finish;
  }

private:
  int start = 0;
  int finish = 0;

};

#endif // RANGE_H
