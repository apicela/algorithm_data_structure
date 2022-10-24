

#include <stdio.h>
int main()
{
    int fact =10, incrementa, v[800], resultado=0,sobra=0,temp[800];
    incrementa =0;
    int tamanho=0, count=0;  

    for( int i=0;i<=800;i++){
        v[i]=NULL;
        temp[i]=NULL;
    }

    temp[0]=2;

            for (int factValue=3; factValue<=fact;factValue++) // para cada fatorial. devemos multiplicar todos v[] existentes
            {
                if(incrementa==1)
                {
                    tamanho++;
                }
                if (factValue>10)
                {
                    printf("");
                }
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
                                    resultado = resultado+v[i]/10;
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
                }


for (int k=tamanho; k>=0; k--){

        printf("%d", v[k]);
    
}

}