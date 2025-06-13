//
//  Interpolate_Correct.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#include "Interpolate_Correct.hpp"

void Interpolate_Correct(Array<double>& uf, Array<double>& uc)
{
    double v;
    int i, j, fi, fj;
    
    // Loop over coarse grid points
    for (i = 1; i < (uc.n_rows - 1); ++i)
    {
        fi = 2 * i;
        for (j = 1; j < (uc.n_cols - 1); ++j)
        {
            fj = 2 * j;
            v = uc(i, j);
            
            uf(fi, fj) = uf(fi, fj) + v;
            uf(fi-1, fj) = uf(fi-1, fj) + v;
            uf(fi, fj-1) = uf(fi, fj-1) + v;
            uf(fi-1, fj-1) = uf(fi-1, fj-1) + v;
        }
    }
}
