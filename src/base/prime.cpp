#include "prime.h"
#include <cmath>
#include <iostream>

using std::sqrt;

std::vector<long long> Prime::prime_list = {2LL,3LL};

PrimeIter::PrimeIter() : my_iter(Prime::prime_list.cbegin()) {}

void Prime::add_next_prime() {
  long long x = prime_list.back();

  while(true) {
    long long y = sqrt(++x);

    for(const auto &i : prime_list) {
      if (i > y) {
        prime_list.push_back(x);
        return;
      }
      if (divisible(x, i)) break;
    }
  }

}
