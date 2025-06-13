//
//  Treat_Boundary.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#include "Treat_Boundary.hpp"

void Treat_Boundary(int lev, Array<double>* Sol)
{
    int i, j;
    
    // Treat left and right boundary
    for (i = 0; i < Sol[lev].n_rows; ++i)
    {
        Sol[lev](i, 0) = Sol[lev](i, 1);
        Sol[lev](i, Sol[lev].n_cols-1) = Sol[lev](i, Sol[lev].n_cols-2);
    }
    
    // Treat upper and lower boundary
    for (j = 0; j < Sol[lev].n_cols; ++j)
    {
        Sol[lev](0, j) = Sol[lev](1, j);
        Sol[lev](Sol[lev].n_rows-1, j) = Sol[lev](Sol[lev].n_rows-2, j);
    }
}
