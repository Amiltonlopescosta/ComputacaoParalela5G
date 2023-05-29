#include <stdio.h>
#include <stdlib.h>

#include <omp.h>


void SerieTaylor( double ln,long double* soma);


 double factorial( int n ) {
    if (n == 0) return 1;

    int i;
    double result = 1;

    for ( i=1; i<=n; i++ )
                result *= i;

    return result;
}
int main(int argc, char* argv[])
{
        long double soma=0.0 ;
         int ln = 1000000;
         int threadnum=2;

        // int thread_count = strtol(argv[1], NULL, 10);
              //     int thread_count = 4;

         #pragma omp parallel num_threads(threadnum)
          SerieTaylor(ln, &soma);

          printf("ln(%d) = %.2Lf\n", ln, soma);
          return 0;
 }
 void SerieTaylor( double ln, long double* soma)   
 {   
   int my_rank = omp_get_thread_num();      
   int thread_count = omp_get_num_threads(); 
   double inicio = (ln/thread_count)*my_rank + 1;    
   double fim = inicio + (ln/thread_count) - 1; 
   double d;     
   double somaparcial;      
   for (d=inicio; d<=fim; d++) somaparcial+=1/factorial(d);  
   printf("Hello from thread  %d\n",my_rank);      
   #pragma omp critical 
   *soma += somaparcial;  
 }        


