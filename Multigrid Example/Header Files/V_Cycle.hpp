//
//  V_Cycle.hpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#ifndef V_Cycle_hpp
#define V_Cycle_hpp

#include <stdio.h>
#include "Array.hpp"
#include "GaussSeidel.hpp"
#include "Restrict_Residual.hpp"
#include "Interpolate_Correct.hpp"

void V_Cycle(int lev, Array<double>* Sol, Array<double>* RHS, int N_PRE, int N_POST, int N_COARSE, int N_LEVELS, double alpha, double* invh2);

#endif /* V_Cycle_hpp */
