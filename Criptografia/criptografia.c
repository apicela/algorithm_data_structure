/*
Objetivo:
Desencriptar o código que segue este padrão:
> Substituir os espaços pelo símbolo # e completar a mensagem com este mesmo símbolo no final, 
caso tenha uma quantidade ímpar de letras;
> Substituir cada letra por outra, utilizando a cifra de César com uma rotação 
à esquerda de cinco posições;
> Subdividir a mensagem em blocos de n letras (neste caso n=2);
> Refletir cada bloco;
> Permutar os blocos trocando o primeiro com o último, o terceiro com a antepenúltimo, 
e assim por diante, mas deixando os outros como estão.
> Adicionar 5 dígitos no inicio da string da mensagem contendo o número binário que corresponde à posição
 da string em que será adicionado um caracter extra (a posição e o caracter são escolhidos aleatoriamente).
*/

#include <stdio.h>
#include <string.h>   
#include <math.h>

int rngBinarie();
int myPow();
void removeChar();

void removeChar(char *str, unsigned int index) {
    char *src;
    for (src = str+index; *src != '\0'; 
    *src = *(src+1),++src) ;
    *src = '\0';
}

int rngBinarie(char* senha)
  {
    double numberPosition=0;
    for(int i=0; i<5;i++)
    {
      numberPosition =  numberPosition+((senha[i]-'0')*myPow(2, 4-i));
    }
    return numberPosition;
  }

int myPow(int base, int exp)
{
int vbase;
if(exp==0){
return 1;
}
else {
vbase = base * myPow(base, exp-1);
return vbase;
}
}

int main()
{
  int numberPosition;
char senha[1000]="12345678";
char par[1000]="", impar[1000]="";
char aux;
  int countPar=0;
  int countImpar=0;


numberPosition= rngBinarie(senha);
//printf("senha pso rng binarie: %s\n", senha);

removeChar(senha, numberPosition);
//printf("senha pos if: %s\n", senha);

// -- separa em par e impar
for(int i=0;i<strlen(senha);i++){
    if(i%2==0)
  {
    par[countPar]=senha[i];
    countPar++;
  }
  else
  {
    impar[countImpar]=senha[i];
    countImpar++;
  }
}

printf("par: %s\n",par);
printf("impar: %s\n",impar);
/*
// -- permuta os blocos
printf(" test - %c XD\n",par[(strlen(par)-1-0)]);
printf("manul %c \n",par[3]);
int louco =(strlen(par)-0);
printf("number %i\n",louco); */
for(int i =0;i<(strlen(par))/2;(i++))
{
    if(i%2==0){
    char auxPar=par[i];
    par[i]=par[(strlen(par)-i-1)];
    par[(strlen(par)-i-1)]=auxPar;
    char auxImpar=impar[i];
    impar[i]=impar[strlen(impar)-i-1];
    impar[strlen(impar)-i-1]=auxImpar;}
}

printf("par: %s\n",par);
printf("impar: %s\n",impar);

printf("first senha: %s\n", senha);
// -- inverte posicoes do caracter
    int changePar=0;
  int changeImpar=0;
for(int i=0;i<(strlen(senha));i++)
{
    if(i%2==0)
    {
        senha[i]=impar[changeImpar];
        changeImpar++;
    }
    else{
    senha[i]=par[changePar];
    changePar++;}
} 
   
    printf("senhaaaa: %s\n",senha);
return 0;
}