//
//  Restrict_Residual.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#include "Restrict_Residual.hpp"

void Restrict_Residual(int lev, Array<double>* Sol, Array<double>* RHS, double alpha, double* invh2)
{
    int i, j, fi, fj;
    
    // Loop over coarse grid points
    for (i = 1; i < (RHS[lev+1].n_rows - 1); ++i)
    {
        fi = 2 * i;
        for (j = 1; j < (RHS[lev+1].n_cols - 1); ++j)
        {
            fj = 2 * j;
            RHS[lev+1](i, j) = 0.25 * (RES(fi, fj) + RES(fi-1, fj) + RES(fi, fj-1) + RES(fi-1, fj-1));
        }
    }
}
