#ifndef EULERIO_H
#define EULERIO_H

#include<iostream>

template <typename input_type>
inline void answer_report(int p_num, input_type answer) {
  std::cout << "Answer to Euler Problem " << p_num << " is: "
            << answer << std::endl;
}

inline void usage() {
  std::cout << "This function requires an argument." << std::endl;
  std::cout << "Provide the number of the problem "
            << "to be solved." << std::endl;
}

inline void bad_problem_number() {
  std::cout << "ERROR: Bad problem number (or problem not "
            << "solved yet)." << std::endl;
}

#endif
