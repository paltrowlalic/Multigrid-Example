//
//  FMG_Solver.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 12/06/2025.
//

#include "FMG_Solver.hpp"

double FMG_Solver(Array<double>* Sol, Array<double>* RHS, int N_LEVELS, int N_ITERS, double res_0, double alpha, double* invh2)
{
    double res = res_0, res_old;
    
    // No. of pre-, post-, and coarse sommthing steps
    int N_PRE = 2, N_POST = 1, N_COARSE = 10;
    
    cout << "FMG_Level\t" << "Cycle\t" << "Residual\t\t" << "Residual_Reduction\t" << "Convergence_Factor"<< endl;
    for (int lev = (N_LEVELS-1); lev >= 0; --lev)
    {
        // Do a fixed No. of V-cucles on each level
        for (int i = 0; i < N_ITERS; ++i)
        {
            res_old = res;
            V_Cycle(lev, Sol, RHS, N_PRE, N_POST, N_COARSE, N_LEVELS, alpha, invh2);
            
            // Compute residual as accuracy measure
            res = Residual(lev, Sol, RHS, alpha, invh2);
            
            cout << lev << "\t\t\t" << i << "\t\t" << res << "\t\t" << res_0/res << "\t\t\t" << res/res_old << endl;
        }
        
        // If not finest level, interpolate current solution
        if (lev > 0)
        {
            Interpolate(Sol[lev-1], Sol[lev]);
        }
    }
    
    return res;
}
