#include "fft_parallel.h"

complex<double>* Parallel_Recursive_FFT(complex<double>* a, int n) {
  if ( n == 1 ) {
    return a;
  }

  complex<double> x(0, 2.*M_PI / n);

  complex<double>* a_0 = new complex<double>[n];

  complex<double>* a_1 = new complex<double>[n];
  complex<double>* y_0 = new complex<double>[n];

  complex<double>* y_1 = new complex<double>[n];
  complex<double>* y = new complex<double>[n];


  cilk_for ( int i = 0; i < n; i++ ) {
    if ( i % 2 == 0 ) {
      a_0[i / 2] = complex<double>(a[i].real(), a[i].imag());
    } else {
      a_1[i / 2] = complex<double>(a[i].real(), a[i].imag());
    }
  }

  y_0 = cilk_spawn Parallel_Recursive_FFT(a_0, n / 2);
  y_1 = cilk_spawn Parallel_Recursive_FFT(a_1, n / 2);

  cilk_sync;

  int halve = n / 2;

  complex<double>* u_n = new complex<double>[n];

  cilk_for(int k = 0; k < n; k++) {
    u_n[k] = complex<double>(1,0);
    u_n[k] = pow(M_E, x*complex<double>(k,0));
  }

  cilk_for ( int k = 0; k < halve; k++ ) {
    y[k] = y_0[k] + u_n[k] * y_1[k];
    y[k + (n / 2)] = y_0[k] - u_n[k] * y_1[k];

  }
  //delete a;
  return y;
}