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

  Filter<int> fil([] (const int &x)
    { return ! (x%2); });

  Fibonacci fib;

  auto sve = fil.wrap(fib);

  Cap<int> capi([] (const int &x)
    { return x < 4000000; });

  auto fin = capi.wrap(sve);

  answer_report(p_num, accumulate(fin.begin(), fin.end(), 0));

  return 0;

}
