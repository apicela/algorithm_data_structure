#include <stdio.h>


int main()
{
    char array[]={4, 5, 2, 8, 9, 7};
    char test[1000][1000];

for (int i=0;i<strlen(array);i++)
{
    for(int j=0;j<3;j++)
    {
        test[i][j]=array[j];
        printf("%d\n",test[i][j]);
    }
}
printf("%d\n", test[1][2]);
return 0;
}