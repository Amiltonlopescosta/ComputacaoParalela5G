
#include <stdio.h>      
#include <stdlib.h>   
#include <pthread.h>    
double ln = 1000000, soma = 0;    
int thread_count;   
void *SerieTaylor(void* rank);   
float factorial(int n) 
{   
  int m;     
  if(n==0){    
    return 1;     
  }         
  float resultado = 1;     
  for(m=1;m<=n;m++){  
    resultado *=m;  
  }
  return resultado;    
}  




int main(int argc, char* argv[])  
{  
  long thread = 0;    
  pthread_t* thread_handles;     
  thread_count = 2;
  thread_handles = malloc (thread_count*sizeof(pthread_t));  
  for (thread = 0; thread < thread_count; thread++)     
  {      
    pthread_create(&thread_handles[thread], NULL, SerieTaylor, (void*) thread);    
  }           
  for (thread = 0; thread < thread_count; thread++)     
  {      
    pthread_join(thread_handles[thread], NULL);     
  }   
  free(thread_handles);   
  printf("ln(%d) = %f\n", (int) ln, soma);  
  //free(list); 
  return 0;   
}     
void *SerieTaylor(void* rank)   
{          
  long my_rank = (long) rank;   
  double inicio = my_rank*(ln/2) + 1;       
  double fim = inicio + (ln/2);  
  double d;    
  for (d=inicio; d<=fim; d++) soma += 1/factorial(d);  
  return NULL;   
}        
