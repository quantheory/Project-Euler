#ifndef PROBLEMS_H
#define PROBLEMS_H

#include "EulerStatus.h"
#include "EulerIO.h"

template <int eul_num>
int euler() {
  bad_problem_number(eul_num);
  return EulerStatus::BAD_ARG;
}

template <>
int euler<1>();

template <>
int euler<2>();

template <>
int euler<3>();

template <>
int euler<6>();

int solve_euler(int p_num);

#endif
