
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

struct dadosTeste
{
  int pontoMedio;
  int padrao;
};
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
  int N,L,first=(-1);
  // Łinhas 16 a 33 = Leitura do Arquivo
  printf("Digite o nome do arquivo: ");
   scanf("%s", nomeArquivo);
  arquivoSegmentos = fopen(nomeArquivo, "r");
  if (arquivoSegmentos == NULL)
  {
    printf("Erro no arquivo.");
  }
  fscanf(arquivoSegmentos, "%d", &L);
  struct dadosTeste armazenamento[L];
  int contagem=0;
  for(;contagem<L; contagem++) {
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
          if(item[i].valor==128){
            armazenamento[contagem].pontoMedio= item[i].pontoMedio;
            if(first==-1){
              first=contagem;}
          }
          if(i+4<totalSegmentos){
            if( item[i].tipoSegmento == 1 && item[i+1].tipoSegmento == 3
                && item[i+2].tipoSegmento == 2 && item[i+3].tipoSegmento == 3 
                && item[i+4].tipoSegmento == 1)
              {
                padrao =1;
              }
          }
        }

      armazenamento[contagem].padrao=padrao; // armazena se segue o padrao ou não
  }
  int totalPadrao=0;
  for (int i =0; i<L;i++)
  {
    totalPadrao=armazenamento[i].padrao+totalPadrao;
    //printf("i:%d -%d - %d\n",i, armazenamento[i].padrao, armazenamento[i].pontoMedio);
  }
  //printf("%d / %d e %d\n", first,armazenamento[first].pontoMedio,armazenamento[L-1].pontoMedio);
  float value = (float)armazenamento[first].pontoMedio/(float)armazenamento[L-1].pontoMedio;
  //HORA DOS PRINTS
  //printf("VALUE: %f", value);
  if(totalPadrao<L*0.7)
  {
    printf("Resultado: Formato da pista nao estimado.");
  }
  else if(0.7<value && value <1.3){
        printf("Resultado: Pista em linha reta.");
  }
    else if(value>1.3){
      printf("Resultado: Curva a direita.");
    }
    else
    {
            printf("Resultado: Curva a esquerda.");
    }
  fclose(arquivoSegmentos);
  return 0;
}   
