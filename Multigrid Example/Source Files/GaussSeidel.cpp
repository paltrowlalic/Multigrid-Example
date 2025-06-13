//
//  GaussSeidel.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#include "GaussSeidel.hpp"

void GaussSeidel(int lev, Array<double>* Sol, Array<double>* RHS, double alpha, double* invh2)
{
    double denom = 1.0 / (4.0 * invh2[lev] + alpha);
    int i, j;
    
    // Assure boundary conditions
    Treat_Boundary(lev, Sol);
    
    // Gauss-Seidel relaxation with damping parameter
    for (i = 1; i < (Sol[lev].n_rows - 1); ++i)
    {
        for (j = 1; j < (Sol[lev].n_cols - 1); ++j)
        {
            Sol[lev](i, j) = (RHS[lev](i, j) + invh2[lev] * (Sol[lev](i+1, j) + Sol[lev](i-1, j) + Sol[lev](i, j+1) + Sol[lev](i, j-1))) * denom;
        }
    }
    
    // Assure boundary conditions
    Treat_Boundary(lev, Sol);
}
