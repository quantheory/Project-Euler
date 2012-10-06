#ifndef RANGE_H
#define RANGE_H

#include <iterator>

class Range;

class RangeIter;

bool operator==(const RangeIter &, const RangeIter &);
bool operator!=(const RangeIter &, const RangeIter &);

class RangeIter
  : public std::iterator<std::bidirectional_iterator_tag, long long> {

public:
  RangeIter() = default;

  // Dereferencing
  long long operator*() const {
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
  long long i = 0LL;
  RangeIter(long long n) : i(n) {}

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
  Range(long long m, long long n) : start(m), finish(n) {}

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
  long long start = 0LL;
  long long finish = 0LL;

};

#endif // RANGE_H
