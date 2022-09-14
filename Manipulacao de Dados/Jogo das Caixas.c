/* 
Objetivo: ler um arquivo .txt com valores de caixas e 
descobrir em qual fileira e caixa se encontra o maior
valor possível somando a caixa da fileira atual +
as fileiras anteriores.
PS: a cada fileira, há uma nova caixa, formando uma piramide.
sendo N a quantidade de fileiras que possui.
Ex:
4 > valor N
                10
              -15 2
             3 20 -50
            8 25 30 42
A resposta de maior valor possível nessa ordem é: fileira 3,  caixa2.
*/

#include <stdio.h>
int main()
{
    FILE *file;
    char userDocument[400];
    int caixaValor[1000][1000], soma[300];
    int i,j, max=0, N, somaTotal=0, fileira, coluna, maxJ[400];

    printf("Digite o nome do arquivo de entrada: "); // "Enter the input file name"
    scanf("%s", userDocument);
    file = fopen(userDocument, "r");
    fscanf(file, "%d", &N);
    
        for(i=1;i<N+1;i++)
        {
            maxJ[i]=-99999999;
            for(j=1;j<i+1;j++)
            {
                fscanf(file,"%d\n", &caixaValor[i][j]);
                soma[i] = soma[i]+caixaValor[i][j];
                if(caixaValor[i][j]>maxJ[i])
                {
                    maxJ[i] = caixaValor[i][j];
                }
                if(somaTotal+maxJ[i]>max)
                {
                   max = somaTotal+maxJ[i];
                   fileira =i;
                   coluna = j;
                }
            }
        somaTotal= somaTotal+soma[i];
        }
    printf("Resposta: fileira %d, caixa %d.", fileira, coluna); 
    fclose(file);
    return 0;
}

