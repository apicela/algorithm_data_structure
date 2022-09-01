#include <stdio.h>
int mult(int base, int exp);
int main(){
int base, exp,test;
printf("Digite a base e o expoente inteiros: ");
scanf(" %i %i", &base, &exp);
test = mult(base,exp);
printf("Resultado: %i", test);
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


}
