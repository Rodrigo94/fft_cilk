/*
fft_serial - Implementaçõe seriais para a transformada rápida de Fourier
*/

#include "fft_serial.h"
#include "fft_parallel.h"
#include <time.h>

using namespace std;

int main() {

  complex<double>* a = new complex<double>[1048576];
  for ( int i = 0; i < 1048576; i++ ) {
    a[i] = complex<double>(i, 1048576 - i);
  }
  clock_t start = clock();
  complex<double>* s1 = Parallel_Recursive_FFT(a, 1048576);
  clock_t end = clock();
  float sec = (float)(end - start) / CLOCKS_PER_SEC;
  cout << sec << " seconds elapsed!" << endl;
}
