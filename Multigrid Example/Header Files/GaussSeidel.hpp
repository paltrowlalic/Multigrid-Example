//
//  GaussSeidel.hpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#ifndef GaussSeidel_hpp
#define GaussSeidel_hpp

#include <stdio.h>
#include "Array.hpp"
#include "Treat_Boundary.hpp"

void GaussSeidel(int lev, Array<double>* Sol, Array<double>* RHS, double alpha, double* invh2);

#endif /* GaussSeidel_hpp */
