#include "EulerIO.h"

#include "Problems.h"

int main(int argc, char **argv) {

  if (argc < 2) {
    usage();
    return -1;
  }
  else {
    return solve_euler(argv[1]);
  }

}
