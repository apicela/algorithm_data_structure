
/*
LAED1 - Analise de segmentos com elementos iguais
Alunos(as): Gabriel Neri Ferreira Santos e Jamil de Souza Apicela Neto
Data: 02/11/2022
****************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// estrutura de elemento dos segmentos
typedef struct {
  int Chave;
  int numElementos; 
  int tipoSegmento;
  int valor;
  int pontoMedio;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}
/*
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{   ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- 
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL) 
  { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) 
    { printf("%d ", Aux -> Item.tipoSegmento);
      Aux = Aux -> Prox;
    }
}
 //////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////ARMAZENANDO DADOS EM ALOCAÇAO DINAMICA//////////////////////////////////
   //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Criaçao de um vetor alocado dinamicamente 2 x N
  int **segmento;

  segmento = (int **)malloc(2 * sizeof(int *));

  for (int i = 0; i < 2; i++)
  {
    segmento[i] = (int *)malloc(N * sizeof(int));
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
    } *//////////////////////////////////////////////////////////////////////////////////////////////////




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

  // VARIAVEIS
  TipoItem item[N];
  int K = 0, count = 1, last,position=0, oldposition=0;
  TipoLista lista;
  //TipoApontador p;
  int elementosVetor[N];

  for (int i = 0; i < N; i++)
  {
    fscanf(arquivoSegmentos, "%d ", &elementosVetor[i]);
  }

  // ve quantos segmentos há no arquivo
  for (int i = 0; i < N; i++)
  {
    position++;
    last = elementosVetor[i];
    if ((elementosVetor[i + 1]) == last && (i+1)!=N)
    {
      ++count; // conta a quantidade de elementos repetidos sequencialmente
    }
    else
    {
      item[K].pontoMedio= (oldposition+position)/2;
      oldposition = position;
      item[K].valor = elementosVetor[i]; // após contar a sequencia de elementos, é salvo
      item[K].numElementos = count;      // o valor do elemento e quantas vezes se repete
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
    crescenteValor[i]=item[i].valor;
  }
  
ordenar(crescenteValor, K); // pega os valores obtidos e os ordena de forma crescente
K = deletarElementosDuplicados(crescenteValor, K); // deleta elementos repetidos

    for(int i=0; i<totalSegmentos;i++) // percorre todos os segmentos
    {
        for(int j=1; j<=K;j++) // a cada vez percorrida do segmento, verifica em qual tipo de 
        {                      // segmento, o elemento se atribui.
            if(item[i].valor==crescenteValor[j-1])
            {
                item[i].tipoSegmento = j;
            }
        }
    }
  free(crescenteValor);
  FLVazia(&lista);

  /*Insere cada chave na lista */
  for (int i = 0; i < totalSegmentos; i++)
    { 
      Insere(item[i], &lista);
    }

  // PADRAO: 1 3 2 3 1 
  int padrao =0;
  for(int i=0; i < totalSegmentos; i++)
  {
    if(i+4<totalSegmentos){
      if( item[i].tipoSegmento == 1 && item[i+1].tipoSegmento == 3
          && item[i+2].tipoSegmento == 2 && item[i+3].tipoSegmento == 3 
          && item[i+4].tipoSegmento == 1)
        {
          padrao =1;
        }
    }
  }

    if(padrao == 1)
    {
      printf("Resultado: Padrao encontrado.");
    }
      else
      {
        printf("Resultado: Padrao nao encontrado.");
      } 

  fclose(arquivoSegmentos);
  return 0;
}   