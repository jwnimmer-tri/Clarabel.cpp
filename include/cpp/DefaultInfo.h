#pragma once

#include "DefaultSolution.h"

#include <cstdint>
#include <type_traits>

namespace clarabel
{

template<typename T = double>
struct DefaultInfo
{
    static_assert(std::is_same<T, float>::value || std::is_same<T, double>::value, "T must be float or double");

    T mu;
    T sigma;
    T step_length;
    uint32_t iterations;
    T cost_primal;
    T cost_dual;
    T res_primal;
    T res_dual;
    T res_primal_inf;
    T res_dual_inf;
    T gap_abs;
    T gap_rel;
    T ktratio;
    double solve_time;
    clarabel::SolverStatus status;
    // NB : `PrintStream stream` not passed to C++ API
};

// Instantiate the templates
template struct DefaultInfo<double>;
template struct DefaultInfo<float>;

} // namespace clarabel