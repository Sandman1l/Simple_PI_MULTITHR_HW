#include <stdio.h>
#include <time.h>
#include "pthread.h"

pthread_t tid[4];
long cantidadIntervalos = 1000000000;
double baseIntervalo;
double Sum[4];

void *PI_CalcOne(){
double fdx;
double acum = 0;
long i=0;
double x = 0;
  for (;i < 250000000;i++) {
		fdx=4/(1+ (x*x));
		acum = acum + (fdx*baseIntervalo);
		x = x + baseIntervalo;
	}
Sum[0] = acum;

pthread_exit(NULL);
}
void *PI_CalcTwo(){
double fdx;
double acum = 0;
long i = 250000000;
double x = 0.25;
  for (;i < 500000000;i++) {
		fdx=4/(1+ (x*x));
		acum = acum + (fdx*baseIntervalo);
		x = x + baseIntervalo;
	}
Sum[1] = acum;

pthread_exit(NULL);
}

void *PI_CalcThree(){
double fdx;
double acum = 0;
long i = 500000000;
double x = 0.5;
  for (;i < 750000000;i++) {
		fdx=4/(1+ (x*x));
		acum = acum + (fdx*baseIntervalo);
		x = x + baseIntervalo;
	}
Sum[2] = acum;

pthread_exit(NULL);
}
void *PI_CalcFour(){
double fdx;
double acum = 0;
long i = 750000000;
double x = 0.75;
  for (;i < 1000000000;i++) {
		fdx=4/(1+ (x*x));
		acum = acum + (fdx*baseIntervalo);
		x = x + baseIntervalo;
	}
Sum[3] = acum;

pthread_exit(NULL);
}
int main() {
/// create all threads
baseIntervalo = 1.0/cantidadIntervalos;
double acum=0;
struct timespec start, finish;
double elapsed;
clock_gettime(CLOCK_MONOTONIC,&start);

  pthread_create(&tid[0], NULL, PI_CalcOne, NULL);
  pthread_create(&tid[1], NULL, PI_CalcTwo, NULL);
  pthread_create(&tid[2], NULL, PI_CalcThree, NULL);
  pthread_create(&tid[3], NULL, PI_CalcFour, NULL);
/// wait all threads by joining them
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  pthread_join(tid[2], NULL);
  pthread_join(tid[3], NULL);
clock_gettime(CLOCK_MONOTONIC,&finish);

elapsed = (finish.tv_sec - start.tv_sec);
elapsed += (finish.tv_nsec - start.tv_nsec)/ 1000000000.0;
  for (int i = 0; i < 4; i++) {
      acum = acum + Sum[i];
  }

	printf("Resultado = %20.18lf (%f)\n",acum,elapsed);
}
