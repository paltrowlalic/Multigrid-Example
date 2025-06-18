//
//  main.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 10/06/2025.
//

#include <iostream>
#include "Array.hpp"
#include "Restrict.hpp"
#include "Residual.hpp"
#include "FMG_Solver.hpp"

using namespace std;

double alpha = double(0.0001);
// grid level factor 1/h^2
double *invh2;

int main(int argc, const char * argv[]) {
    
    int i, N_ROWS, N_COLS, N_LEVELS, N_ITERS;
    N_ROWS = 1024;
    N_COLS = 1024;
    N_LEVELS = 11;
    N_ITERS = 2;
    
    // Solution and right hand side on each level
    Array<double>* Sol = new Array<double>[N_LEVELS];
    Array<double>* RHS = new Array<double>[N_LEVELS];
    
    // Add 1 ghost layer in each direction
    int size_add = 2;
    invh2 = new double[N_LEVELS];
    
    // Allocate memory on each grid level
    for (i = 0; i < N_LEVELS; ++i)
    {
        Sol[i].resize(N_ROWS + size_add, N_COLS + size_add);
        RHS[i].resize(N_ROWS + size_add, N_COLS + size_add);
//        cout << "i: " << i << endl;
//        cout << "N_ROWS: " << Sol[i].n_rows << "\t\t N_COLS: "<< Sol[i].n_cols << endl;
        N_ROWS = (N_ROWS / 2);
        N_COLS = (N_COLS / 2);
        invh2[i] = 1.0 / pow(4.0,i);
//        cout << "invh2: " << invh2[i] << endl;
        cout << endl;
    }
    
    // Initialize solution and right hand side
    Sol[N_LEVELS - 1].initrandom();
    Sol[0] = 9999999.0;
    // Simply set f = 0 tp obtain the solution u = 0
    RHS[0] = 0.0;
    
    // Restrict right hand side to all coarse grids
    for (i = 1; i < N_LEVELS; ++i)
    {
        Restrict(RHS[i-1], RHS[i]);
    }
    
    // Compute normalized starting residual
    double res_0 = Residual(0, Sol, RHS, alpha, invh2);
    cout << "Starting residual: " << res_0 << endl;
    cout << endl;
    
    // Call FMG solver
    double res_final;
    res_final = FMG_Solver(Sol, RHS, N_LEVELS, N_ITERS, res_0, alpha, invh2);
    cout << endl;
    cout << "Residual after FMG_iteration: " << res_final << endl;
    cout << endl;
    
    delete [] invh2;
    delete [] Sol;
    delete [] RHS;
    
    cout << endl;
    
    return 0;
}

