//
//  Restrict.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 12/06/2025.
//

#include "Restrict.hpp"

void Restrict(Array<double>& fine, Array<double>& coarse)
{
    // Loop over coarse grid points
    int i, j, fi, fj;
    for (i = 1; i < (coarse.n_rows - 1); ++i)
    {
        fi = 2 * i;
        for (j = 1; j < (coarse.n_cols - 1); ++j)
        {
            fj = 2 * j;
            coarse(i,j) = 0.25 * (fine(fi,fj) + fine(fi-1,fj) + fine(fi,fj-1), fine(fi-1,fj-1));
        }
    }
}
