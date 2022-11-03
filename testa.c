/****************
LAED1 - Analise de segmentos com elementos iguais

Alunos(as): Gabriel Neri Ferreira Santos e Jamil de Souza Acélio Neto

Data: 02/11/2022

****************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ordenar(int *vetor, size_t tamanho);
int main()
{
  FILE *arquivoSegmentos;
  char nomeArquivo[49];
  int N;
  // Recebe-se o nome do arquivo, o qual e aberto em sequencia
  printf("Digite o nome do arquivo: ");
  // scanf("%s", nomeArquivo);
  arquivoSegmentos = fopen("teste.txt", "r");
  if (arquivoSegmentos == NULL)
  {
    printf("Erro no arquivo.");
  }
  fscanf(arquivoSegmentos, "%d", &N);
  printf("%d\n", N);
  int elementosVetor[N];
  for (int i = 0; i < N; i++)
  {
    fscanf(arquivoSegmentos, "%d ", &elementosVetor[i]);
  }

  int K = 0, count = 1, quantidadeNumeros = 0, last;

  int **segmento;

  segmento = (int **)malloc(2 * sizeof(int *));

  for (int i = 0; i < 2; i++)
  {
    segmento[i] = (int *)malloc(N * sizeof(int));
  }





  struct elementos
  {
    int numElementos;
    int tipoSegmento;
    int valor;
  };
  struct elementos elemento[500];

  // ve quantos segmentos
  for (int i = 0; i < N; i++)
  {
    last = elementosVetor[i];
    if ((elementosVetor[i + 1]) == last)
    {
      ++count;
    }
    else
    {
      elemento[K].valor = elementosVetor[i];
      elemento[K].numElementos = count;
      last = elementosVetor[i + 1];
      count = 1;
      K++;
    }
  }


  int *crescenteValor;
  crescenteValor = (int *)malloc(K*sizeof(int));

  for(int i=0;i<K;i++) 
  {
    crescenteValor[i]=elemento[i].valor;
  }
  
    void ordenar(int *vetor, size_t tamanho) {
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}
ordenar(crescenteValor, K);

  for(int i=0;i<K;i++)
  {
    printf("%d\n", crescenteValor[i]);
  }

  int i=0;
    do
    if (crescenteValor[i] == crescenteValor[i+1])
    {
      for (; i<K; i++){
      crescenteValor[i]=crescenteValor[i+1];
      }
      K--;
      i++;
    }while( i<K);
  
  for (int i=0; i<K; i++)
    {
      if(crescenteValor[0]!=crescenteValor[i])
      {
        count++;
      }
    }  
    printf("%d\n", count);
  fclose(arquivoSegmentos);
  return 0;
}   
