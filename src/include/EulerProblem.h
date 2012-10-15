#ifndef EULERPROBLEM_H
#define EULERPROBLEM_H

#include "EulerIO.h"
#include "Problems.h"

#include <functional>
#include <stdexcept>
#include <utility>
#include <map>

template <int p_num>
constexpr std::pair<int, std::function<int (std::string&)>>
  solver_pair_make() {
  return std::pair<int, std::function<int (std::string&)>>
    (p_num, euler_solver<p_num>);
}

const std::map<int, std::function<int (std::string&)>>
  solvers_map =
{
  solver_pair_make<1>(),
  solver_pair_make<2>(),
  solver_pair_make<3>(),
  solver_pair_make<6>(),
};

class EulerProblem {
public:

  EulerProblem(int num)
    : p_num(num) {
    try {
      solve_routine = solvers_map.at(p_num);
    } catch (std::out_of_range err) {
      bad_problem_number(p_num);
      solve_routine = [] (std::string&) ->int
        { return EulerStatus::BAD_ARG; };
    }
  }

  std::string get_solution() {
    if (solution.empty()) solve_routine(solution);
    return solution;
  }

  int print_solve() {
    const int status = solve_routine(solution);
    if (!status) answer_report(p_num, solution);
    return status;
  }

  int get_num() const { return p_num; }

private:
  int p_num;

  std::function<int (std::string&)> solve_routine;

  std::string solution = "";

};

#endif //EULERPROBLEM_H
