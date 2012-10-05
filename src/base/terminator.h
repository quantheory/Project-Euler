#ifndef TERMINATOR_H
#define TERMINATOR_H

#include "indicator.h"
#include "iter_wrap_tools.h"
#include <iterator>

#ifndef NDEBUG
#include <type_traits>
#endif

template <typename>
class Terminator;

template <typename>
class TerminatorIter;

template <typename Iterator>
bool operator==(const TerminatorIter<Iterator> &,
                const TerminatorIter<Iterator> &);

template <typename Iterator>
bool operator!=(const TerminatorIter<Iterator>&,
                const TerminatorIter<Iterator>&);

template <typename Iterator>
class TerminatorIter
  : public std::iterator<std::input_iterator_tag, IterVal<Iterator> > {

#ifndef NDEBUG
  static_assert(std::is_base_of<
                std::input_iterator_tag,
                typename std::iterator_traits<Iterator>::iterator_category>::value,
                "Tried to instantiate TerminatorIter with non-input iterator.");
#endif

public:

  typedef IterVal<Iterator> value_type;

  // Remove default constructor and assignment.
  TerminatorIter() = delete;
  TerminatorIter &operator=(const TerminatorIter &) = delete;

  // Can be copy-constructed.
  TerminatorIter(const TerminatorIter &) = default;

  // Increment
  TerminatorIter &operator++() {
    if (!terminated) terminated = !test(curr_val = *++source_iter);
    return *this;
  }

  TerminatorIter operator++(int) {
    TerminatorIter old_val = *this;
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
  friend bool operator==<Iterator>(const TerminatorIter&, const TerminatorIter&);
  friend bool operator!=<Iterator>(const TerminatorIter&, const TerminatorIter&);

protected:
  const Indicator<value_type> &test;
  value_type curr_val;

private:
  Iterator source_iter;
  bool terminated = true;

  // Construct with an iterator, a termination indicator,
  // and a reference to an Indicator.
  TerminatorIter(const Iterator iter, bool term,
            const Indicator<value_type> &ind)
    : test(ind),
      curr_val(*iter),
      source_iter(iter),
      terminated(term)
  {
    terminated = term || !test(curr_val);
  }

  // Make sure this can be accessed by any Terminator
  // that produces this type of TerminatorIter.
  template <typename>
  friend class Terminator;
  
};

template <typename Iterator>
inline bool operator==(const TerminatorIter<Iterator>& lhs,
                       const TerminatorIter<Iterator>& rhs) {
  return ! (lhs != rhs);
}

template <typename Iterator>
inline bool operator!=(const TerminatorIter<Iterator>& lhs,
                       const TerminatorIter<Iterator>& rhs) {
  return lhs.terminated != rhs.terminated &&
    lhs.source_iter != rhs.source_iter;
}

template <typename Container>
class Terminator {

public:

  typedef TerminatorIter< ContIter<const Container> > iterator_type;

  // Due to the references, cannot use these defaults.
  Terminator() = delete;
  Terminator &operator=(const Terminator &) = delete;

  // Can do copy constructor, though.
  Terminator(const Terminator &) = default;

  // More useful constructor.
  Terminator(const Container &contain,
        const Indicator<typename iterator_type::value_type> &ind)
    : source(contain), test(ind) {}

  iterator_type begin() const {
    return iterator_type(source.begin(), false, test);
  }

  iterator_type end() const {
    return iterator_type(source.end(), true, test);
  }

  bool empty() const {
    return this->source.begin() == this->source.end();
  }

protected:

  const Container &source;
  const Indicator<typename iterator_type::value_type> &test;

};

#endif //TERMINATOR_H
