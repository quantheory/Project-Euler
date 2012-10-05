#ifndef ITER_WRAP_TOOLS_H
#define ITER_WRAP_TOOLS_H

#include <iterator>
#include <utility>

template <typename Iterator>
using IterVal = typename std::iterator_traits<Iterator>::value_type;

template <typename Container>
using ContIter = decltype(std::declval<Container>().begin());

#endif // ITER_WRAP_TOOLS_H
