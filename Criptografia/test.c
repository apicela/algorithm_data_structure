#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void removeChar();
void removeChar(char *str, unsigned int index) {
    char *src;
    for (src = str+index; *src != '\0'; *src = *(src+1),++src) ;
    *src = '\0';
}

int main()
{
int numberPosition=8;
char senha[]="01000helokity";
printf(" number posit %c\n", senha[numberPosition]);
removeChar(senha, numberPosition);
printf("%s\n", senha);

return 0;
}