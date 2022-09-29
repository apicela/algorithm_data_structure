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

int rngBinarie(char* numberPosition)
  {
    double removePosition=0;
    for(int i=0; i<5;i++)
    {
      removePosition =  removePosition+((numberPosition[i]-'0')*myPow(2, 4-i));
    }
    return removePosition;
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
      FILE *file;
    char userDocument[400];
  char numberPosition[200];
    printf("Digite o nome do arquivo: \n"); // "Enter the input file name"
    scanf("%s", userDocument);
    file = fopen(userDocument, "r");
char senha[5000];
printf("--------------------\n");
printf("Mensagem codificada:\n");
printf("--------------------\n");

for(int i=0;i<5;i++){
    fscanf(file, "%c\n", &numberPosition[i]);
}
for(int i=0;i<5000;i++){
    fscanf(file, "%c\n", &senha[i]);
}
printf("%s%s\n\n",numberPosition,senha);
int removePosition= rngBinarie(numberPosition);
removeChar(senha, (removePosition-1));


char par[1000]="", impar[1000]="";
  int countPar=0;
  int countImpar=0;

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


// -- permuta os blocos

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

   // cifra cesar
  for(int i = 0; i < strlen(senha); i++)
  	{
      if(senha[i]!='#')
      {
      switch(senha[i])
      {
        case 'A':
        senha[i]='V';
        break;

        case 'B':
        senha[i]='W';
        break;

        case 'C':
        senha[i]='X';
        break;

        case 'D':
        senha[i]='Y';
        break;

        case 'E':
        senha[i]='Z';
        break;

        case 'a':
        senha[i]='v';
        break;

        case 'b':
        senha[i]='w';
        break;

        case 'c':
        senha[i]='x';
        break;

        case 'd':
        senha[i]='y';
        break;

        case 'e':
        senha[i]='z';
        break;

      default:
      senha[i]=senha[i]-5;
      break;
      }
      }

	}
//replace all # to ' '
  for(int i = 0; i < strlen(senha); i++)
  	{
  		if(senha[i] == '#')  
		{
  			senha[i] = ' ';
 		}
	}
printf("----------------------\nMensagem decodificada:\n----------------------\n");
printf("%s\n",senha);
return 0;
}