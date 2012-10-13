#ifndef EULERIO_H
#define EULERIO_H

#include<iostream>

int parse_int(char* arg_in, int& int_out) noexcept;

inline void usage() {
  std::cerr << "This function requires one integer argument."
            << std::endl;
  std::cerr << "Provide the number of the problem "
            << "to be solved." << std::endl;
}

inline void bad_problem_number(int p_num) {
  std::cerr << "ERROR: Bad problem number (or problem not "
            << "solved yet): " << p_num << std::endl;
}

template <typename input_type>
inline void answer_report(int p_num, input_type answer) {
  std::cout << "Answer to Euler Problem " << p_num << " is: "
            << answer << std::endl;
}

#endif // EULERIO_H
