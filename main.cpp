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
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;
int main(int argc, char* argv[]) {
  int SERIE_SIZE = atoi(argv[1]);
  int n = pow(2, SERIE_SIZE);
  complex<double>* a = new complex<double>[n];

  //Parte Abaixo � gerado o vetor a ser alvo da transformada:

  /*for ( int i = 0; i < n; i++ ) {
    a[i] = complex<double>(sin((double(i) / n) * 2 * M_PI), 0);
  }*/

  for ( int i = 0; i < n; i++ ) {
    if (i < n / 2 )
    a[i] = complex<double>(1, 0);
    else
    a[i] = complex<double>(0, 0);
  }

  /////////////////////////////////////////////////////////////


  //Execu��o e Medi��o:
  //clock_t start = clock();
  complex<double>* s1 = Parallel_Recursive_FFT(a, n); //Execu��o//
  //clock_t end = clock();
  //float sec = (float)(end - start) / CLOCKS_PER_SEC;
  //cout << sec << " seconds elapsed!" << endl;

  /*//S�rie � escrita em arquivo:
  ofstream fs;
  fs.open("Results/teste.txt", ofstream::out);
  for ( int i = 0; i < n; i++ ) {
    fs << s1[i] << endl;
  }
  fs.close();*/

  for ( int i = 0; i < 10; i++ ) {
    cout
    << i << ":\t"
    << a[i].real() << " \t "
    << s1[i].real() << "\t+ " << s1[i].imag() << "i"
    << endl;
    }
}
