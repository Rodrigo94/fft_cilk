/*
fft_serial - Implementa��es seriais para a transformada r�pida de Fourier
fft_parallel - Implementa��es paralelas para a transformada r�pida de Fourier

Ferramentas:
  - Microsoft Visual Studio 2013;
  - Intel Cilk Plus;
  - Intel Parallel Studio XE 13;
  - CUDA ToolKit v6;
  ...

Considera��es:
  - Estou assumindo que a s�rie ter� tamanho igual a uma pot�ncia de 2;
  - A vari�vel SERIE_SIZE indica o tamanho da s�rie em expoentes;
  - Arquivos geradores de s�ries diferentes estar�o dispon�veis;
    - Fun��o Degrau;
    - Onda triangular;
    - Onda Quadrada;
    - Fun��o Seno;
    - Fun��o Cosseno;
    - Decaimento Exponencial;
    ...
  - Um script em python para plotar os resultados estar� dispon�vel;
  - A implementa��o em CUDA ser� feita para validar esta;
  - Ser� implementado em um ambiente distribu�do futuramente;
  ...

Notas:
  - Pode ser feita uma implementa��o serial habilitando o cilk para "modo serial"
  ...
*/
#include "fft_serial.h"
#include "fft_parallel.h"
#include <math.h>
#include <time.h>
using namespace std;
const int SERIE_SIZE = 4;
int main() {
  int n = pow(2, SERIE_SIZE);
  complex<double>* a = new complex<double>[n];
  for ( int i = 0; i < n; i++ ) {
    a[i] = complex<double>(sin((double(i) / n) * 2 * M_PI), 0);
  }
  clock_t start = clock();
  complex<double>* s1 = Parallel_Recursive_FFT(a, n); //Execu��o//
  clock_t end = clock();
  float sec = (float)(end - start) / CLOCKS_PER_SEC;
  cout << sec << " seconds elapsed!" << endl;
  for ( int i = 0; i < n; i++ ) {
    cout
      << i << ": "
      << a[i].real() << " ---> "
      << s1[i].real() << " + " << s1[i].imag() << "i"
      << endl;
  }
}
