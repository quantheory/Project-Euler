#include "Problems.h"
#include "EulerStatus.h"

#include <numeric>
#include "range.h"

using std::string;
using std::to_string;

template <>
int euler_solver<6>(string& solution) {

  Range r(1LL,101LL);

  auto f = [] (const long long &x, const long long &y) { return x - y*y; };

  long long v1 = accumulate(r.begin(), r.end(), 0LL);

  solution = to_string(accumulate(r.begin(),r.end(),v1 *= v1,f));

  return EulerStatus::SUCCESS;

}
