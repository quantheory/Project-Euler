#include "Problems.h"
#include "EulerIO.h"

#include <numeric>
#include "fibonacci.h"
#include "filter.h"
#include "cap.h"
#include "terminator.h"

template <>
int euler<2>() {

  int p_num = 2;

  Filter<long long> fil([] (const long long &x)
    { return ! (x%2LL); });

  Fibonacci fib;

  auto sve = fil.wrap(fib);

  Cap<long long> capi([] (const long long &x)
    { return x < 4000000LL; });

  auto fin = capi.wrap(sve);

  answer_report(p_num, accumulate(fin.begin(), fin.end(), 0LL));

  return 0;

}
