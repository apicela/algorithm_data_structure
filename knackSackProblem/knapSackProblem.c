#include <stdio.h>

int max(int a, int b);

int max(int a,int b)
{
    if(a<b)
    {
        return b;
    }
    else
    {
        return a;
    }
} 
int main()
{
    FILE *file;
    char userDocument[300];
    int bags=0, slotsBags[100], items=0, itemPrice[100], itemWeight[100], 
    choice[100][100], amountItems[100], maxSlots=0, table[2000][1000]; 
    printf("Digite o nome do arquivo: \n"); // "Enter the input file name"
    
    scanf("%s", userDocument);
    file = fopen(userDocument, "r");
    // read quantity bags
    fscanf(file,"%d\n", &bags); 

         // read capacity bags
        for(int i=0; i<bags;i++)  // OK
        {
            fscanf(file,"%d", &slotsBags[i]);
        }
    // read quantity items
    fscanf(file,"%d",&items);

        // read weight and price for each item
        for(int i=1; i<items+1;i++) // OK
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
    
        for(int i=0; i<bags; i++) // OK
        {
            if(slotsBags[i]>maxSlots)
            {
                maxSlots = slotsBags[i];
            }
        }
// ------ TESTS AREA
    // idea: create a dynamic program 
    printf("max %d\n", maxSlots);
    printf("items: %d\n",items);
    printf("weight 4: %d\n", itemWeight[4]);
    for(int i=1; i<=items; i++)
    {
        printf("%d %d\n", itemPrice[i],itemWeight[i]);
    }

printf("- - - -\n");

// END TESTS

    for(int i=0; i<=maxSlots; i++) 
    {
        for(int j=0;j<=(items); j++) 
        {
            if(i==0 | j==0)
            {
                table[i][j]=0;
            }
            else if(itemWeight[j]<=i) // NEED A SERIOUSLY REWORK
            {
                table[i][j]=max((itemPrice[j]+table[i-itemWeight[j]][j-1]), table[i][j-1]);
            }
            else
            {
                table[i][j]=table[i][j-1];
            }
        }
    } 

        for(int i=0;i<=maxSlots; i++)
        {
for(int j=0; j<=items; j++)
    {
        //printf("%d%d  %d  ", i,j,table[i][j]);
        printf("%d ", table[i][j]);
        }
        printf("\n");
    }
printf("%d ",table[65][6]);


}