#include "Problems.h"
#include "EulerIO.h"

#include <numeric>
#include "range.h"
#include "filter.h"

template <>
int euler<1>() {

  int p_num = 1;

  auto f = [] (const long long &x)
    { return ! (x%3LL && x%5LL); };

  Filter<long long> fil(f);

  auto sve = fil.wrap(Range(1LL,1000LL));

  answer_report(p_num, accumulate(sve.begin(), sve.end(), 0LL));

  return 0;

}
