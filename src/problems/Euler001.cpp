#include "Problems.h"
#include "EulerStatus.h"

#include <numeric>
#include "range.h"
#include "filter.h"

using std::string;
using std::to_string;

template <>
int euler_solver<1>(string& solution) {

  auto f = [] (const long long &x)
    { return ! (x%3LL && x%5LL); };

  Filter<long long> fil(f);

  auto sve = fil.wrap(Range(1LL,1000LL));

  solution = to_string(accumulate(sve.begin(), sve.end(), 0LL));

  return EulerStatus::SUCCESS;

}
