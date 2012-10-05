#include "Problems.h"

#include <string>

using std::stoi;

int solve_euler(char* arg_in) {
  int p_num = std::stoi(arg_in);
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
    return euler<0>();
  }
}
