#include <stdio.h>


int main()
{
    FILE *file;
    char userDocument[300];
    int bags, slotsBags[100], items, itemPrice[100], itemWeight[100], choice[100][100], amountItems[100]; 
    printf("Digite o nome do arquivo: \n"); // "Enter the input file name"
    scanf("%s", userDocument);
    file = fopen(userDocument, "r");
    // read quantity bags
    fscanf(file,"%d\n", &bags);

         // read capacity bags
        for(int i=0; i<bags;i++)
        {
            fscanf(file,"%d", &slotsBags[i]);
        }
    // read quantity items
    fscanf(file,"%d",&items);

        // read weight and price for each item
        for(int i=0; i<items;i++)
        {
            fscanf(file,"%d %d\n", &itemWeight[i],&itemPrice[i]);
        }

         // read picked item
        for(int i=0; i<items;i++)
        {
            for(int j=1; j<=bags;j++)
            {
                if(j==bags)
                {
                    fscanf(file,"%d\n", &choice[i][j]);
                }
                else
                fscanf(file,"%d", &choice[i][j]);
            }
        }
    
    /*
    if(amountItems[i]>slotsBags[i])
    {
        printf("Solução inviavel\n");
    } */















}