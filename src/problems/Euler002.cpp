#include "Problems.h"
#include "EulerStatus.h"

#include <numeric>
#include "fibonacci.h"
#include "filter.h"
#include "cap.h"
#include "terminator.h"

using std::string;
using std::to_string;

template <>
int euler_solver<2>(string& solution) {

  Filter<long long> fil([] (const long long &x)
    { return ! (x%2LL); });

  Fibonacci fib;

  auto sve = fil.wrap(fib);

  Cap<long long> capi([] (const long long &x)
    { return x < 4000000LL; });

  auto fin = capi.wrap(sve);

  solution = to_string(accumulate(fin.begin(), fin.end(), 0LL));

  return EulerStatus::SUCCESS;

}
