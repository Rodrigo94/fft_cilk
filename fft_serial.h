#ifndef FFT_SERIAL

#include<complex>
#include<iostream>
#include "advisor-annotate.h"


#define M_PI 3.14159265358979
#define M_E 2.71828182845904

using namespace std;

complex<double>* Recursive_FFT(complex<double>* a, int n);

complex<double>* Iterative_FFT(complex<double>* a, int n);

complex<double>* Bit_Reverse_Copy(complex<double>* a, int n);

#endif // !FFT_SERIAL
