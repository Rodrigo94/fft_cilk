/*
fft_serial - Implementaçõe seriais para a transformada rápida de Fourier
*/

#include "fft_serial.h"

using namespace std;

int main() {
  cout << "Agora vou testar o fft com :" << endl;
  complex<double> a[8];
  a[0] = complex<double>(1, 0);
  a[1] = complex<double>(1, 0);
  a[2] = complex<double>(1, 0);
  a[3] = complex<double>(1, 0);
  a[4] = complex<double>(0, 0);
  a[5] = complex<double>(0, 0);
  a[6] = complex<double>(0, 0);
  a[7] = complex<double>(0, 0);

  complex<double>* s = Recursive_FFT(a, 8);

  for ( int i = 0; i < 8; i++ ) {
    cout << s[i].real() << " " << s[i].imag() << endl;
  }
}
