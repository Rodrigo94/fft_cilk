#include "fft_parallel.h"

complex<double>* Parallel_Recursive_FFT(complex<double>* a, int n) {
  // Caso base:
  if ( n == 1 ) {
    return a;
  }

  int halve = n / 2;

  complex<double> x(0, 2.*M_PI / n);

  complex<double>* a_0 = new complex<double>[n];
  complex<double>* a_1 = new complex<double>[n];
  complex<double>* y_0 = new complex<double>[n];
  complex<double>* y_1 = new complex<double>[n];
  complex<double>* y = new complex<double>[n];

  cilk_for(int i = 0; i < halve; i++) {
  //for(int i = 0; i < halve; i++) {
    a_0[i] = complex<double>(a[i + i].real(), a[i + i].imag());
    a_1[i] = complex<double>(a[i + i + 1].real(), a[i + i].imag());
  }
  

  y_0 = cilk_spawn Parallel_Recursive_FFT(a_0, halve);
  y_1 = cilk_spawn Parallel_Recursive_FFT(a_1, halve);

  cilk_sync;

  

  //y_0 = Parallel_Recursive_FFT(a_0, halve);
  //y_1 = Parallel_Recursive_FFT(a_1, halve);

  cilk_for ( int k = 0; k < halve; k++ ) {
  //for(int k = 0; k < halve; k++) {
    complex<double>u = pow(M_E, x*complex<double>(k, 0));
    y[k] = y_0[k] + u * y_1[k];
    y[k + (halve)] = y_0[k] - u * y_1[k];
  }
  return y;
}