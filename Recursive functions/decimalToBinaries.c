#include <stdio.h>
void dec2bin(int dec);

int main(){
    int dec;
    printf("Digite um numero inteiro: ");
    scanf("%i", &dec);
    printf("Resultado: ");
    dec2bin(dec);
    return 0;
}

void dec2bin(int dec){
    if(dec/2 != 0){
     dec2bin(dec/2);
       printf("%d", dec%2);

    }
    else{
     printf("%d", dec%2);
    }
}

int mult(int base, int exp){
int vbase;
if(exp==0){
return 1;
}
else {
vbase = base * mult(base, exp-1);
return vbase;
}