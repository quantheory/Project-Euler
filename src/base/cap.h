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

  Cap(const SimpleIndicator<T> &ind) 
    : test_ptr(std::make_shared< SimpleIndicator<T> >(ind)) {}

  Cap(SimpleIndicator<T> &&ind) {
    test_ptr = std::make_shared<SimpleIndicator<T>>
      (std::forward<SimpleIndicator<T>>(ind));
  }

  Cap(bool f(const T&)) {
    test_ptr = std::make_shared<SimpleIndicator<T>>(f);
  }

  template <typename Container>
  Terminator<Container> wrap(const Container &source) const {
    return Terminator<Container>(source, *test_ptr);
  }

protected:
  std::shared_ptr< Indicator<T> > test_ptr;

};

#endif // CAP_H
