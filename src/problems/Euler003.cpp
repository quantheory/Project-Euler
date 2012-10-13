#include "Problems.h"
#include "EulerIO.h"

#include <cmath>
#include "prime.h"
#include "cap.h"

using std::sqrt;

template <>
int euler<3>() {

  int p_num = 3;

  constexpr long long test_val = 600851475143LL;

  long long curr_val = test_val;

  Prime my_prime;

  Cap<long long> capi([] (const long long &x) -> bool { return x <= sqrt(test_val); });

  auto term = capi.wrap(my_prime);

  for (const auto &i : term) {
    if (divisible(curr_val, i)) {
      curr_val /= i;
      if (curr_val == 1LL) {
        curr_val = i;
        break;
      }
    }
  }

  answer_report(p_num, curr_val);

  return 0;

}
