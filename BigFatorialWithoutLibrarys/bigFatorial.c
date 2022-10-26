#include <stdio.h>
int main()
{
    int fact, v[6000], resultado=0,tamanho=0,temp[6000], incrementa=0;

    for( int i=0;i<=6000;i++){
        v[i]=NULL;
        temp[i]=NULL;
    } 
printf("Digite um numero inteiro: ");
    scanf("%d", &fact);
    temp[0]=2;


            for (int factValue=3; factValue<=fact;factValue++) // para cada fatorial. devemos multiplicar todos v[] existentes
            {
                incrementa=0;   
                for(int i=0; i<(tamanho+1);i++) // começa com 0
                {
                    resultado = temp[i]*factValue;
                        if(incrementa==1)
                        {
                            v[i]=resultado%10+v[i];
                        }
                        else
                        {
                            v[i]=resultado%10;
                        }
                                if(v[i]/10>0)
                                {
                                    resultado = resultado+(v[i]-(v[i]%10));
                                    v[i]=v[i]%10;
                                }

                    resultado = (resultado-(resultado%10))/10;


                    if(resultado>0)
                    {
                        incrementa=1;
                    }

                    temp[i+1]=v[i+1];
                    v[i+1]=resultado;                    
                    temp[i]=v[i];
                }
                            if(incrementa==1)
                {
                    tamanho++; 
                }
                }
}