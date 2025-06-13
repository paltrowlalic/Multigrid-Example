//
//  Residual.hpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 12/06/2025.
//

#ifndef Residual_hpp
#define Residual_hpp

#include <stdio.h>
#include "Array.hpp"

#define RES(i, j) (RHS[lev](i, j) + invh2[lev]*(Sol[lev](i+1, j) + Sol[lev](i, j+1) + Sol[lev](i, j-1) + Sol[lev](i-1, j)) - (4.0*invh2[lev] + alpha)*Sol[lev](i,j))

double Residual(int lev, Array<double>* Sol, Array<double>* RHS, double alpha, double* invh2);

#endif /* Residual_hpp */
