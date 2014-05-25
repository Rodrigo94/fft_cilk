/*
fft_serial - Implementaçõe seriais para a transformada rápida de Fourier
*/

#include "fft_serial.h"
#include "fft_parallel.h"

using namespace std;

int main() {
  complex<double>* a = new complex<double>[1048576];
  for ( int i = 0; i < 1048576; i++ ) {
    a[i] = complex<double>(i, 1048576 - i);
  }
  complex<double>* s1 = Recursive_FFT(a, 1048576);
}
