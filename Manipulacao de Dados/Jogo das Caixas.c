#include <stdio.h>

int main()
{
    FILE *file;
    char userDocument[400];
    int caixaValor[2][2];
    int i,j, max=0, N, soma=0, fileira, coluna;

    printf("Digite o nome do arquivo de entrada: "); // "Enter the input file name"
    scanf("%s", userDocument);

    file = fopen(userDocument, "r");
    fscanf(file, "%d", &N);
    
        for(i=0;i<N;i++)
        {
            for(j=1;j<i+1;j++)
            {
                fscanf(file,"%d\n", &caixaValor[i][j]);
                soma = soma+caixaValor[i][j];
                if(soma>max)
                {
                   max = soma;
                   fileira =i;
                   coluna = j;
                }
            }
        }
    printf("Resposta: fileira %d, caixa %d\n", fileira, coluna); 
    fclose(file);
    return 0;
}

