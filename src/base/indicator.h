#ifndef INDICATOR_H
#define INDICATOR_H

#include <functional>

template<typename T>
using Indicator = std::function<bool (const T &)>;

#endif //INDICATOR_H
