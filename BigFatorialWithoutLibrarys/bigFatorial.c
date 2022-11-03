#include <stdio.h>
int main()
{
    int fact=4, v[6000], resultado=0,tamanho=0, i=0, k=0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &fact);
    v[0]=1;

        for(int n=2; n<=fact; n++)
        {
                resultado = n*v[k];
                v[k] = resultado%10;
                resultado /=10;

                    while(resultado>0)
                    {
                        v[++k] = resultado%10;
                        resultado/=10;
                    }
                            k=0;
        }

    for(int i=k; i>=0; i--)
    {
        printf("%d", v[k]);
    }
}