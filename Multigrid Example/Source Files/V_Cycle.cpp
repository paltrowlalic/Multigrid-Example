//
//  V_Cycle.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 13/06/2025.
//

#include "V_Cycle.hpp"

void V_Cycle(int lev, Array<double>* Sol, Array<double>* RHS, int N_PRE, int N_POST, int N_COARSE, int N_LEVELS, double alpha, double* invh2)
{
    int i;
    
    // Solve problem on coarsest grid
    if (lev == (N_LEVELS - 1))
    {
        for (i = 0; i < N_COARSE; ++i)
        {
            GaussSeidel(lev, Sol, RHS, alpha, invh2);
        }
    }
    else
    // or recusively do V-cycle
    {
        // Do some presommthing steps
        for (i = 0; i < N_PRE; ++i)
        {
            GaussSeidel(lev, Sol, RHS, alpha, invh2);
        }
        //Compute and restrict the residual
        Restrict_Residual(lev, Sol, RHS, alpha, invh2);
        
        // Initialize the coarse solution to zero
        Sol[lev+1] = 0;
        
        V_Cycle(lev+1, Sol, RHS, N_PRE, N_POST, N_COARSE, N_LEVELS, alpha, invh2);
        
        // Interpolate error and correct fine solution
        Interpolate_Correct(Sol[lev], Sol[lev+1]);
        
        // Do some postsmoothing steps
        for (i = 0; i < N_POST; ++i)
        {
            GaussSeidel(lev, Sol, RHS, alpha, invh2);
        }
    }
}
