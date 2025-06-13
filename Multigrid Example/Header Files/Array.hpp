//
//  Array.hpp
//  Multigrid Example
//
//  Created by Jiangnan Zhang on 10/06/2025.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <class T> class Array
{
public:
    // Data member
    T* data;
    int n_rows;
    int n_cols;
    int n_total;
    
    // Member method/function
    void resize(int i, int j);
    void initrandom();
    
    // Overloaded operators
    Array& operator=(const double a);   // declare overloaded assignment operator '='
    T& operator()(int i, int j);     // declare overloaded '()' operator
    
//    ~Array();

};

#endif /* Array_hpp */
