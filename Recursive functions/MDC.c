#include<stdio.h>
// Máximo Divisor Comum
int mdc(int a, int b);
int main(){
int a, b, test;
printf("Digite dois numeros inteiros: ");
scanf("%i %i", &a,&b);
test = mdc(a,b);
printf("Resultado: %i", test);
}

int mdc(int a, int b){
    if(b==0){
        return a;
    }
    else {
    
     return   mdc(b,a%b);
    
    }
}
