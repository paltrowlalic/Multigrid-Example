//
//  Array.cpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 10/06/2025.
//

#include "Array.hpp"
using namespace std;

template <class T>
void Array<T>::resize(int i, int j)
{
    n_rows = i;             // Set No. of rows
    n_cols = j;             // Set No. of columns
    n_total = n_rows * n_cols;  // Set No. of total points
    data = new T[n_total];  // Allocate memory for data
}

// Initilize all data value with same value between 0 and 1
template <class T>
void Array<T>::initrandom()
{
    srand(time(NULL));        // Initialize random seed using current time
    double r = double(rand()) / double(RAND_MAX);   // Generate random number between 0 and 1
//    cout << r << endl;
    
    for (int i = 0; i < n_total; ++i)
    {
        data[i] = r;        // Initilize all data value with same value between 0 and 1
    }
}

// Overloaded assignment operator '='
template <class T>
Array<T>& Array<T>::operator=(const double a)
{
    for (int i = 0; i < n_total; ++i)
    {
        data[i] = a;
    }
    return *this;
}

// Overloaded '()' operator
template <class T>
T& Array<T>::operator()(int i, int j)
{
    return data[i*n_cols + j];
}

template class Array<double>;
