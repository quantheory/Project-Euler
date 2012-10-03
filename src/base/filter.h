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

  Filter(const SimpleIndicator<T> &ind) 
    : test_ptr(std::make_shared< SimpleIndicator<T> >(ind)) {}

  Filter(SimpleIndicator<T> &&ind) {
    test_ptr = std::make_shared<SimpleIndicator<T>>
      (std::forward<SimpleIndicator<T>>(ind));
  }

  Filter(bool f(const T&)) {
    test_ptr = std::make_shared<SimpleIndicator<T>>(f);
  }

  template <typename Container>
  Sieve<Container> wrap(const Container &source) const {
    return Sieve<Container>(source, *test_ptr);
  }

protected:
  std::shared_ptr< Indicator<T> > test_ptr;

};

#endif // FILTER_H
