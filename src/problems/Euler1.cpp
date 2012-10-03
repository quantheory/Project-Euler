#include "Problems.h"
#include "EulerIO.h"

#include <numeric>
#include "range.h"
#include "filter.h"

template <>
int euler<1>() {

  int p_num = 1;

  auto f = [] (const int &x)
    { return ! (x%3 && x%5); };

  Filter<int> fil(f);

  auto sve = fil.wrap(Range(1,1000));

  answer_report(p_num, accumulate(sve.begin(), sve.end(), 0));

  return 0;

}
