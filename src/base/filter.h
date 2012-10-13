#ifndef FILTER_H
#define FILTER_H

#include <memory>
#include "indicator.h"
#include "sieve.h"

// Factory class for sieves (from iterators)
template <typename T>
class Filter {

public:
  Filter() = default;

  Filter(const Filter &) = default;

  Filter(Indicator<T> in_test)
    : test(in_test) {}

  template <typename Container>
  Sieve<Container> wrap(const Container &source) const {
    return Sieve<Container>(source, test);
  }

protected:
  Indicator<T> test;

};

#endif // FILTER_H
