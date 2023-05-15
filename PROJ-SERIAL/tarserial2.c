#include <stdio.h>
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
int main ()     
{   
  int i, n;   
  double sum=0.0;      
  int ln=1000000;  
  for (i=0; i<ln; i++) sum +=1/ factorial(i);  
  printf("The value is %lf\n", sum);    
  return 0;  
} 
   

    
    
    
