#ifndef SIEVE_H
#define SIEVE_H

#include "indicator.h"
#include "iter_wrap_tools.h"
#include <iterator>

#ifndef NDEBUG
#include <type_traits>
#endif

template <typename>
class Sieve;

template <typename>
class SieveIter;

template <typename Iterator>
bool operator==(const SieveIter<Iterator> &,
                const SieveIter<Iterator> &);

template <typename Iterator>
bool operator!=(const SieveIter<Iterator>&,
                const SieveIter<Iterator>&);

template <typename Iterator>
class SieveIter
  : public std::iterator<std::input_iterator_tag, IterVal<Iterator> > {

#ifndef NDEBUG
  static_assert(std::is_base_of<
                std::input_iterator_tag,
                typename std::iterator_traits<Iterator>::iterator_category>::value,
                "Tried to instantiate SieveIter with non-input iterator.");
#endif

public:

  typedef IterVal<Iterator> value_type;

  // Remove default constructor and assignment.
  SieveIter() = delete;
  SieveIter &operator=(const SieveIter &) = delete;

  // Can be copy-constructed.
  SieveIter(const SieveIter &) = default;

  // Increment
  SieveIter &operator++() {
    while (++source_iter != end_iter &&
           ! test(curr_val = *source_iter));
    return *this;
  }

  SieveIter operator++(int) {
    SieveIter old_val = *this;
    ++*this;
    return old_val;
  }

  // Dereference
  value_type operator*() const {
    return curr_val;
  }
  const value_type *operator->() const {
    return &curr_val;
  }

  // End of iteration test
  friend bool operator==<Iterator>(const SieveIter&, const SieveIter&);
  friend bool operator!=<Iterator>(const SieveIter&, const SieveIter&);

protected:
  const Indicator<value_type> &test;
  value_type curr_val;

private:
  Iterator source_iter;
  Iterator end_iter;

  // Construct with an iterator, an ending iterator,
  // and a reference to an Indicator.
  SieveIter(const Iterator iter, const Iterator end,
            const Indicator<value_type> &ind)
    : test(ind),
      curr_val(*iter),
      source_iter(iter),
      end_iter(end)
  {
    if (!test(curr_val)) ++*this;
  }

  // Make sure this can be accessed by any Sieve
  // that could produce this type of SieveIter.
  template <typename>
  friend class Sieve;
  
};

template <typename Iterator>
inline bool operator==(const SieveIter<Iterator>& lhs,
                       const SieveIter<Iterator>& rhs) {
  return lhs.source_iter == rhs.source_iter;
}

template <typename Iterator>
inline bool operator!=(const SieveIter<Iterator>& lhs,
                       const SieveIter<Iterator>& rhs) {
  return lhs.source_iter != rhs.source_iter;
}

template <typename Container>
class Sieve {

public:

  typedef SieveIter< ContIter<const Container> > iterator_type;

  // Due to the references, cannot use these defaults.
  Sieve() = delete;
  Sieve &operator=(const Sieve &) = delete;

  // Can do copy constructor, though.
  Sieve(const Sieve &) = default;

  // More useful constructor.
  Sieve(const Container &contain,
        const Indicator<typename iterator_type::value_type> &ind)
    : source(contain), test(ind) {}

  iterator_type begin() const {
    return iterator_type(source.begin(), source.end(), test);
  }

  iterator_type end() const {
    return iterator_type(source.end(), source.end(), test);
  }

  bool empty() const {
    return this->source.begin() != this->source.end();
  }

protected:

  const Container &source;
  const Indicator<typename iterator_type::value_type> &test;

};

#endif //SIEVE_H
