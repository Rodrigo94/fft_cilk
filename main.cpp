/*
fft_serial - Implementações seriais para a transformada rápida de Fourier
fft_parallel - Implementações paralelas para a transformada rápida de Fourier

Ferramentas:
  - Microsoft Visual Studio 2013;
  - Intel Cilk Plus;
  - Intel Parallel Studio XE 13;
  - CUDA ToolKit v6;
  ...

Considerações:
  - Estou assumindo que a série terá tamanho igual a uma potência de 2;
  - A variável SERIE_SIZE indica o tamanho da série em expoentes;
  - Arquivos geradores de séries diferentes estarão disponíveis;
    - Função Degrau;
    - Onda triangular;
    - Onda Quadrada;
    - Função Seno;
    - Função Cosseno;
    - Decaimento Exponencial;
    ...
  - Um script em python para plotar os resultados estará disponível;
  - A implementação em CUDA será feita para validar esta;
  - Será implementado em um ambiente distribuído futuramente;
  ...

Notas:
  - Pode ser feita uma implementação serial habilitando o cilk para "modo serial"
  ...
*/
#include "fft_serial.h"
#include "fft_parallel.h"
#include <fstream>
#include <ittnotify.h>
#include <cilk\cilk_api.h>
#include <math.h>
#include <time.h>
using namespace std;
int main(int argc, char* argv[]) {

  int SERIE_SIZE = atoi(argv[1]);
  int n = pow(2, SERIE_SIZE);
  complex<double>* a = new complex<double>[n];

  //Parte Abaixo é gerado o vetor a ser alvo da transformada:

  /*for ( int i = 0; i < n; i++ ) {
    a[i] = complex<double>(sin((double(i) / n) * 2 * M_PI), 0);
  }*/

  for ( int i = 0; i < n; i++ ) {
    if (i < n / 2 )
    a[i] = complex<double>(1, 0);
    else
    a[i] = complex<double>(0, 0);
  }

  // Execução e Medição:
  // API Intel VTune para medição:
  __itt_resume();
  complex<double>* s1 = Parallel_Recursive_FFT(a, n); //Execução//
  __itt_pause();
  
}
