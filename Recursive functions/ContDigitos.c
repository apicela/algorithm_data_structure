#include <stdio.h>
// Contador de Digitos
int Digitos(int N);
int main(){
    int N;
printf("Digite um numero inteiro: ");
scanf("%i", &N);
printf("Resultado: %i ", Digitos(N));
}

int Digitos(int N){

    if (N <=10){
        return 1;
    }

    else {
        int base = Digitos(N/10);
        base++;
        return  base;
    }
}