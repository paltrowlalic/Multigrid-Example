//
//  FMG_Solver.hpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 12/06/2025.
//

#ifndef FMG_Solver_hpp
#define FMG_Solver_hpp

#include <stdio.h>
#include "Array.hpp"
#include "V_Cycle.hpp"
#include "Residual.hpp"
#include "Interpolate.hpp"

double FMG_Solver(Array<double>* Sol, Array<double>* RHS, int N_LEVELS, int N_ITERS, double res_0, double alpha, double* invh2);

#endif /* FMG_Solver_hpp */
