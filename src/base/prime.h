#ifndef PRIME_H
#define PRIME_H

#include <vector>

inline bool divisible(const long long &i, const long long &div) {
  return !(i%div);
}

class Prime;

class PrimeIter;

bool operator==(const PrimeIter &lhs, const PrimeIter &rhs);
bool operator!=(const PrimeIter &lhs, const PrimeIter &rhs);

class PrimeIter
  : public std::iterator<std::bidirectional_iterator_tag, long long> {

public:

  PrimeIter();

  long long operator*() const {
    return *my_iter;
  }

  PrimeIter &operator++();

  PrimeIter operator++(int);

  PrimeIter &operator--();

  PrimeIter operator--(int);

private:
  typename std::vector<long long>::const_iterator my_iter;

};

inline bool operator==(const PrimeIter &, const PrimeIter &){
  return false;
}

inline bool operator!=(const PrimeIter &, const PrimeIter &){
  return true;
}

class Prime {

public:

  PrimeIter begin() const {
    return PrimeIter();
  }

  PrimeIter end() const {
    return PrimeIter();
  }

  static std::vector<long long> prime_list;

private:

  static void add_next_prime();

  friend class PrimeIter;

};

inline PrimeIter &PrimeIter::operator++() {
    ++my_iter;
    if (my_iter == Prime::prime_list.cend()) {
      Prime::add_next_prime();
      my_iter = Prime::prime_list.cend()-1;
    }
    return *this;
}

inline PrimeIter PrimeIter::operator++(int) {
  PrimeIter old_val(*this);
  ++*this;
  return old_val;
}

inline PrimeIter &PrimeIter::operator--() {
  --my_iter;
  return *this;
}

inline PrimeIter PrimeIter::operator--(int) {
  PrimeIter old_val(*this);
  --*this;
  return old_val;
}

#endif
