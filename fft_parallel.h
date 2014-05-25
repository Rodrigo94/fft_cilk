#ifndef FFT_PARALLEL

#include<complex>
#include<iostream>
#include<cilk\cilk.h>

#define M_PI 3.14159265358979
#define M_E 2.71828182845904

using namespace std;

complex<double>* Parallel_Recursive_FFT(complex<double>* a, int n);


#endif // !FFT_PARALLEL