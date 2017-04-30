#include <stdio.h>
#include <time.h>
#include "pthread.h"


pthread_t tid[4];

long cantidadIntervalos = 1000000000;
double baseIntervalo;
double Sum[4];

void PI_Calc(long i, double x, long Inter, int index){
double fdx;
double acum = 0;
  for (;i<Inter;i++) {
		fdx=4/(1+x*x);
		acum=acum+(fdx*baseIntervalo);
		x=x+baseIntervalo;
	}
Sum[index] = acum
}

void main() {
/// create all threads
baseIntervalo = 1.0/cantidadIntervalos;
double acum=0;
start = clock();

  pthread_create(&tid[0], NULL, PI_Calc(0,0.0,250000000,0), NULL);
  pthread_create(&tid[1], NULL, PI_Calc(250000000,0.25,500000000,0), NULL);
  pthread_create(&tid[2], NULL, PI_Calc(500000000,0.5,750000000,0), NULL);
  pthread_create(&tid[3], NULL, PI_Calc(750000000,0.75,1000000000,0), NULL);
/// wait all threads by joining them
  for (int i = 0; i < 4; i++) {
      pthread_join(tid[i], NULL);
      acum = acum + Sum[i];

  }
  end=clock();

	printf("Resultado = %20.18lf (%ld)\n",acum,end-start);
}
