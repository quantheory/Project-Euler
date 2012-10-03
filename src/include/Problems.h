#ifndef PROBLEMS_H
#define PROBLEMS_H

#include "EulerIO.h"

template <int eul_num>
int euler() {
  bad_problem_number();
  return -1;
}

template <>
int euler<1>();

template <>
int euler<2>();

int solve_euler(char*);

#endif
