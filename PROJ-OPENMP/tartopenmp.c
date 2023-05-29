 #include <stdio.h>  
#include <stdlib.h>     
#include <omp.h>       
void SerieTaylor(double ln, double* soma);    
float factorial(int n)     
{                  
  if (n==0 || n==1)       
    return 1;       
  else   
    return 1/(n * factorial(n-1));   
}           
int main(int argc, char* argv[])      
{      
  double soma = 0;   
  double ln = 1000000;  
  
  int thread_count = strtol(argv[1], NULL, 10);    
  //     int thread_count = 4;     
  #pragma omp parallel num_threads(thread_count)   
  SerieTaylor(ln, &soma);      
  printf("ln(%d) = %f\n", (int) ln, soma);  
  return 0;                
}    

void SerieTaylor(double ln, double* soma)    
 {
   int my_rank = omp_get_thread_num();             
   int thread_count = omp_get_num_threads();      
   double inicio = (ln/thread_count)*my_rank + 1;   
   double fim = inicio + (ln/thread_count) - 1;      
   double somaparcial, d;               
   for (d=inicio; d<=fim; d++) somaparcial = somaparcial + factorial(d);  
   printf("Hello from thread %d from %d\n",my_rank,thread_count);  
   #pragma omp critical    
   *soma += somaparcial;   
 }     
