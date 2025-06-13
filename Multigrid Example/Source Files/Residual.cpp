//
//  Residual.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 12/06/2025.
//

#include "Residual.hpp"

// The residual is computed in the L2 norm
double Residual(int lev, Array<double>* Sol, Array<double>* RHS, double alpha, double* invh2)
{
    double res = 0.0;
    double rf;
    
    for (int i = 1; i < (Sol[lev].n_rows - 1); ++i)
    {
        for (int j = 1; j < (Sol[lev].n_cols - 1); ++j)
        {
            rf = RES(i, j);
            res = res + rf * rf;
        }
    }
    
    return sqrt(res) / (Sol[lev].n_rows * Sol[lev].n_cols);
}
