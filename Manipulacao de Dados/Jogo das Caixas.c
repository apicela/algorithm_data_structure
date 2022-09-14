/* 
Objetivo: ler um arquivo .txt com valores de caixas e 
descobrir em qual fileira e caixa se encontra o maior
valor possível somando a caixa + as fileiras anteriores.
*/

#include <stdio.h>
int main()
{
    FILE *file;
    char userDocument[400];
    int caixaValor[1000][1000], soma[300];
    int i,j, max=0, N, somaTotal=0, fileira, coluna, maxJ[]={0};

    printf("Digite o nome do arquivo de entrada: "); // "Enter the input file name"
    scanf("%s", userDocument);
    file = fopen(userDocument, "r");
    fscanf(file, "%d", &N);
    
        for(i=0;i<N+1;i++)
        {
            int maxJ[]={NULL};
            for(j=1;j<i+1;j++)
            {
                fscanf(file,"%d\n", &caixaValor[i][j]);
                soma[i] = soma[i]+caixaValor[i][j];

                if(caixaValor[i][j]>maxJ[j])
                {
                    maxJ[j] = caixaValor[i][j];
                }

                if(somaTotal+maxJ[j]>max)
                {
               //    max = soma;
                   fileira =i;
                   coluna = j;
                }
                printf("hi%d %d %d\n", maxJ[j], i, j);
            }
        somaTotal= somaTotal+soma[i];
        }
    printf("Resposta: fileira %d, caixa %d.", fileira, coluna); 
    fclose(file);
    return 0;
}

