
/*
LAED1 - Analise de segmentos com elementos iguais
Alunos(as): Gabriel Neri Ferreira Santos e Jamil de Souza Acélio Neto
Data: 02/11/2022
****************/

#include <stdio.h>
#include <stdlib.h>

void ordenar(int *vetor, size_t tamanho);
int deletarElementosDuplicados(int *vetor, int size);

int main()
{
  FILE *arquivoSegmentos;
  char nomeArquivo[49];
  int N;
  // Łinhas 16 a 33 = Leitura do Arquivo
  printf("Digite o nome do arquivo: ");
   scanf("%s", nomeArquivo);
  arquivoSegmentos = fopen(nomeArquivo, "r");
  if (arquivoSegmentos == NULL)
  {
    printf("Erro no arquivo.");
  }
  fscanf(arquivoSegmentos, "%d", &N);
  int elementosVetor[N];
  for (int i = 0; i < N; i++)
  {
    fscanf(arquivoSegmentos, "%d ", &elementosVetor[i]);
  }

  int K = 0, count = 1, last;

// Criaçao de um vetor alocado dinamicamente 2 x N
  int **segmento;

  segmento = (int **)malloc(2 * sizeof(int *));

  for (int i = 0; i < 2; i++)
  {
    segmento[i] = (int *)malloc(N * sizeof(int));
  }

  // estrutura de elemento dos segmentos
  struct elementos
  {
    int numElementos; 
    int tipoSegmento;
    int valor;
  };
  struct elementos elemento[500];

  // ve quantos segmentos há no arquivo
  for (int i = 0; i < N; i++)
  {
    last = elementosVetor[i];
    if ((elementosVetor[i + 1]) == last && (i+1)!=N)
    {
      ++count; // conta a quantidade de elementos repetidos sequencialmente
    }
    else
    {
      elemento[K].valor = elementosVetor[i]; // após contar a sequencia de elementos, é salvo
      elemento[K].numElementos = count;      // o valor do elemento e quantas vezes se repete
      last = elementosVetor[i + 1];          // o novo elemento a ser comparado é o proximo
      count = 1;  // reseta a quantidade de elementos contadas
      K++; // contabiliza a quantidade de segmentos
    }
  }

int totalSegmentos = K; 
  // aloca dinamicamente um vetor para salvar os valores obtidos no arquivo
  int *crescenteValor;
  crescenteValor = (int *)malloc(K*sizeof(int));
  
  for(int i=0;i<K;i++) 
  {
    crescenteValor[i]=elemento[i].valor;
  }
  
ordenar(crescenteValor, K); // pega os valores obtidos e os ordena de forma crescente
K = deletarElementosDuplicados(crescenteValor, K); // deleta elementos repetidos

    for(int i=0; i<totalSegmentos;i++) // percorre todos os segmentos
    {
        for(int j=1; j<=K;j++) // a cada vez percorrida do segmento, verifica em qual tipo de 
        {                      // segmento, o elemento se atribui.
            if(elemento[i].valor==crescenteValor[j-1])
            {
                elemento[i].tipoSegmento = j;
            }
        }
    }

  for(int linha=0; linha<2;linha++) // preenche a matriz alocada dinamicamente na linha 75 e 76
    {
        for(int coluna=0; coluna<totalSegmentos; coluna++)
        {
            if(linha==0){
            segmento[linha][coluna]= elemento[coluna].tipoSegmento; // preenche a 1* linha 
            }                                                       // com o tipo de segmento
            else
            {
            segmento[linha][coluna]= elemento[coluna].numElementos; // preenche a 2* linha
            }                                                       // com a quantidade de 
        }                                                       // elementos de mesmo segmento
    } // element                                                // registrados sequencialmente

    printf("Matriz:\n");
        for(int linha=0; linha<2;linha++) // imprime a matriz
    {
        for(int coluna=0; coluna<totalSegmentos; coluna++)
        {
            printf("%d ", segmento[linha][coluna]);
        }
        printf("\n");
    }

  fclose(arquivoSegmentos);
  return 0;
}   



    //////////////////////////////////////////////////// FUNCOES UTILIZADAS ///////////////////////////////////////////////

        int  deletarElementosDuplicados(int *array,int size)
        {
            for(int i=1;i<size;i++)
            {
                if(array[i]==array[i-1])
                {
                    for (int j=i;j<size;j++)
                    {
                        array[j-1]=array[j];
                    }
                    i--;
                    size--;
                }
            }
          return size;
        }

        void ordenar(int *vetor, size_t tamanho) // void ordenacao retirado do SO
        {
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
/*
    void ordenaSelecao(int *vetor, size_t n )
    {
      int j, i, min;
      int x;
        for(i=1;i=n-1;i++)
        {
          min =i;
           for ( j=i+1;j<=n;j++)
            {
              if(vetor[j]<vetor[min])
              {
              min =j;
              x = vetor[min];
              vetor[min]=vetor[i];
              vetor[i]=x;}
            }
        }
    } */