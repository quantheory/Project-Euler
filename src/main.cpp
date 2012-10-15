#include "EulerIO.h"
#include "EulerProblem.h"

int main(int argc, char **argv) {

  // Make sure correct argument number.
  if (argc != 2) {
    usage();
    return EulerStatus::BAD_ARG;
  } else {

    // Grab problem number from first argument
    // and, if valid, call solve_euler.
    int p_num;
    if (int status = parse_int(argv[1], p_num))
      return status;
    else
      return EulerProblem(p_num).print_solve();
  }

}
