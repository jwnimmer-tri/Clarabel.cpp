#ifndef CLARABEL_DEFAULT_INFO_H
#define CLARABEL_DEFAULT_INFO_H

#include "ClarabelTypes.h"
#include "DefaultSettings.h"
#include "DefaultSolution.h"

#include <stdint.h>


typedef struct ClarabelLinearSolverInfo
{
    ClarabelDirectSolveMethods name;
    uint32_t threads;
    bool direct;
    uint32_t nnzA;
    uint32_t nnzL;
    enum ClarabelSolverStatus status;
} ClarabelLinearSolverInfo;


// ClarabelDefaultInfo types
typedef struct ClarabelDefaultInfo_f64
{
    double mu;
    double sigma;
    double step_length;
    uint32_t iterations;
    double cost_primal;
    double cost_dual;
    double res_primal;
    double res_dual;
    double res_primal_inf;
    double res_dual_inf;
    double gap_abs;
    double gap_rel;
    double ktratio;
    double solve_time;
    enum ClarabelSolverStatus status;
    ClarabelLinearSolverInfo linsolver;
    // NB : `PrintStream stream` not passed to C API
} ClarabelDefaultInfo_f64;

typedef struct ClarabelDefaultInfo_f32
{
    float mu;
    float sigma;
    float step_length;
    uint32_t iterations;
    float cost_primal;
    float cost_dual;
    float res_primal;
    float res_dual;
    float res_primal_inf;
    float res_dual_inf;
    float gap_abs;
    float gap_rel;
    float ktratio;
    double solve_time;
    enum ClarabelSolverStatus status;
    ClarabelLinearSolverInfo linsolver;
    // NB : `PrintStream stream` not passed to C API
} ClarabelDefaultInfo_f32;

#ifdef CLARABEL_USE_FLOAT
typedef ClarabelDefaultInfo_f32 ClarabelDefaultInfo;
#else
typedef ClarabelDefaultInfo_f64 ClarabelDefaultInfo;
#endif /* CLARABEL_USE_FLOAT */

#endif