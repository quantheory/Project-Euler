#include "EulerStatus.h"
#include "Problems.h"

int solve_euler(int p_num) {
  switch (p_num) {
  case 1:
    return euler<1>();
  case 2:
    return euler<2>();
  case 3:
    return euler<3>();
  case 6:
    return euler<6>();
  default:
    bad_problem_number(p_num);
    return EulerStatus::BAD_ARG;
  }
}
