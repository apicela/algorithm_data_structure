#include <stdio.h>

int main()
{
    FILE *file;
    char userDocument[20];
    int caixaValor[2][2];
    int i,j,  N;

    //printf("Digite o nome do arquivo de entrada:");
    //scanf("%s",  &userDocument);
    //file = fopen(userDocument, "r");
    file = fopen("teste.txt", "r");
    fscanf(file, "%d", &N);
    printf("%d\n", N);

        for(i=1;i<N;i++)
        {
            for(j=1;j<i+1;j++)
            {
                fscanf(file,"%d", &caixaValor[i][j]);
            }
        }

    fclose(file);
    return 0;
}

