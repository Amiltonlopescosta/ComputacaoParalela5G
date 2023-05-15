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
      float sum=0;
      for (i=1; i<=1000000; i++) sum = sum + factorial(i);
      printf("The value is %f\n", sum);
      return 0;
}
