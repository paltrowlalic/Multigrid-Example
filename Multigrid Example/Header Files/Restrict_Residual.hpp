//
//  Restrict_Residual.hpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#ifndef Restrict_Residual_hpp
#define Restrict_Residual_hpp

#include <stdio.h>
#include "Array.hpp"
#include "Residual.hpp"

void Restrict_Residual(int lev, Array<double>* Sol, Array<double>* RHS, double alpha, double* invh2);

#endif /* Restrict_Residual_hpp */
