#ifndef CAP_H
#define CAP_H

#include <memory>
#include "indicator.h"
#include "terminator.h"

// Factory class for terminators (from iterators)
template <typename T>
class Cap {

public:
  Cap() = default;

  Cap(const Cap &) = default;

  Cap(Indicator<T> in_test)
    : test(in_test) {}

  template <typename Container>
  Terminator<Container> wrap(const Container &source) const {
    return Terminator<Container>(source, test);
  }

protected:
  Indicator<T> test;

};

#endif // CAP_H
