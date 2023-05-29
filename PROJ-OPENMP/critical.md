Projeto - Computação Paralela
OpenMP é utilizado com o intuito de programar com memória compartilhada, isto é, quando diferentes threads possuem acesso a uma mesma área de memória. Em outras palavras, todas as threads conseguem acessar a memória principal e, por exemplo, uma variável nela alocada, pois ela é compartilhada e global entre as threads.

Sendo assim, nessa API, todos os núcleos possuem acesso à memória RAM. Para permitir esse compartilhamento de memória usando a biblioteca:

#include <omp.h>

#pragma omp critical *soma += somaparcial;

A diretiva utilizada #pragma omp critical impede que duas threads acessem o mesmo local de memória ao mesmo tempo, garantindo o princípio de exclusão mútua. Sendo assim, apenas uma thread por vez pode executar o bloco em seguida da diretiva.
