#ifndef PROBLEMS_H
#define PROBLEMS_H

#include "EulerStatus.h"
#include "EulerIO.h"

#include <string>

template <int eul_num>
int euler_solver(std::string& solution) {
  bad_problem_number(eul_num);
  return EulerStatus::BAD_ARG;
}

template <>
int euler_solver<1>(std::string& solution);

template <>
int euler_solver<2>(std::string& solution);

template <>
int euler_solver<3>(std::string& solution);

template <>
int euler_solver<6>(std::string& solution);

#endif //PROBLEMS_H
