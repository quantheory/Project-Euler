#include "Problems.h"
#include "EulerIO.h"

#include <numeric>
#include "range.h"

template <>
int euler<6>() {

  int p_num = 6;

  Range r(1LL,101LL);

  auto f = [] (const long long &x, const long long &y) { return x - y*y; };

  long long v1 = accumulate(r.begin(), r.end(), 0LL);

  answer_report(p_num, accumulate(r.begin(),r.end(),v1 *= v1,f));

  return 0;

}
