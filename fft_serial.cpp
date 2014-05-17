#include "fft_serial.h"

/*
Implementação Recursiva da Transformada Rápida de Fourier
*/
complex<double>* Recursive_FFT(complex<double>* a, int n) {
  if ( n == 1 ) {
    return a;
  }

  complex<double> u_n;
  complex<double> x(0, 2.*M_PI / n);
  u_n = pow(M_E, x);

  complex<double> u(1, 0);

  complex<double>* a_0 = new complex<double>[n];

  complex<double>* a_1 = new complex<double>[n];
  complex<double>* y_0 = new complex<double>[n];

  complex<double>* y_1 = new complex<double>[n];
  complex<double>* y = new complex<double>[n];


  for ( int i = 0; i < n; i++ ) {
    if ( i % 2 == 0 ) {
      a_0[i / 2] = complex<double>(a[i].real(), a[i].imag());
    } else {
      a_1[i / 2] = complex<double>(a[i].real(), a[i].imag());
    }
  }

  y_0 = Recursive_FFT(a_0, n / 2);
  y_1 = Recursive_FFT(a_1, n / 2);

  for ( int k = 0; k < n / 2; k++ ) {
    y[k] = y_0[k] + u * y_1[k];
    y[k + (n / 2)] = y_0[k] -  u * y_1[k];
    u = u * u_n;

  }
  //delete a;
  return y;
}

/*
Implementação Iterativa da Transformada Rápida de Fourier
*/
complex<double>* Iterative_FFT(complex<double>* a, int n) {
  //Reverse...
  complex<double>* A;
  A = Bit_Reverse_Copy(a, n);
  complex<double> u_n;

  int lgn = log2(n);
  for ( int i = 0; i <= lgn; i++ ) {
    int m = pow(2, i);
    complex<double> x(0, 2.*M_PI / m);
    u_n = pow(M_E, x);
    for ( int k = 0; k < n; k += m ) {
      complex<double> u(1, 0);
      for ( int j = 0; j < m / 2; j++ ) {
        complex<double> t = u*A[k + j + m / 2];
        u = A[k + j];
        A[k + j] = u + t;
        A[k + j + m / 2] = u - t;
        u = u*u_n;
      }
    }
  }
  return A;
}

complex<double>* Bit_Reverse_Copy(complex<double>* a, int n) {
  complex<double>* A = new complex<double>[n];
  for ( int i = 0; i < n; i++ ) {

  }
  return A;
}