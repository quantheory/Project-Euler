#include "Problems.h"
#include "EulerIO.h"

#include <numeric>
#include "range.h"
#include "filter.h"

template <>
int euler<2>() {

  int p_num = 2;

  auto f = [] (const int &x)
    { return ! (x%3 && x%5); };

  Filter<int> fil(f);

  Range nums(1, 4000000);

  auto sve = fil.wrap(nums);

  answer_report(p_num, accumulate(sve.begin(), sve.end(), 0));

  return 0;

}
