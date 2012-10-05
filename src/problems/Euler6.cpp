#include "Problems.h"
#include "EulerIO.h"

#include <numeric>
#include "range.h"

template <>
int euler<6>() {

  int p_num = 6;

  Range r(1,101);

  auto f = [] (const int &x, const int &y) { return x - y*y; };

  int v1 = accumulate(r.begin(), r.end(),0);

  answer_report(p_num, accumulate(r.begin(),r.end(),v1 *= v1,f));

  return 0;

}
