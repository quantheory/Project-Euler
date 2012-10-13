#include "EulerStatus.h"
#include "EulerIO.h"

#include <string>
#include <stdexcept>

using std::stoi;
using std::invalid_argument;
using std::out_of_range;
using std::cerr;
using std::endl;

int parse_int(char* arg_in, int& int_out) noexcept {

  int status;
  try {
    int_out = std::stoi(arg_in);
    status = EulerStatus::SUCCESS;
  } catch (invalid_argument err) {
    std::cerr << "Argument is not an integer!" << std::endl;
    status = EulerStatus::BAD_ARG;
  } catch (out_of_range err) {
    std::cerr << "Integer argument is out of range!" << std::endl;
    status = EulerStatus::BAD_ARG;
  }

  return status;
}
