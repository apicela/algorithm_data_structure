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
    choice[100][100], amountItems[100], maxSlots=0, table[2000][1000], amountWeight[100]; 
    printf("Digite o nome do arquivo: "); // "Enter the input file name"
    
    scanf("%s", userDocument);
    file = fopen(userDocument, "r");

// READING DATA ARCHIVE  --  **     LINES 29-59      **

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
    
    // CALCULATING MAX SLOTS OF BAGS TO CREATE A TABLE

    for(int i=0; i<bags; i++) 
    {
        if(slotsBags[i]>maxSlots)
        {
            maxSlots = slotsBags[i];
        }
    }

    // CREATING A TABLE WITH BEST SOLUTIONS TO MY KNACK_SACK_PROBLEM
    for(int i=0; i<=maxSlots; i++) 
    {
        for(int j=0;j<=(items); j++) 
        {
            if(i==0 || j==0)
            {
                table[i][j]=0;
            }
            else if(itemWeight[j]<=i) 
            {
            // CAN CHECK USED TABLES TO ANALYZE CHOICES TO table[i][j] here: 
            // https://github.com/jamilzin1/AEDS-I/tree/master/knackSackProblem/tableToAnalyzeFormuleElseIF.PNG
                table[i][j]=max((itemPrice[j]+table[i-itemWeight[j]][j-1]), table[i][j-1]);
            }
            else
            {
                table[i][j]=table[i][j-1];
            }
        }
    } 

    // GETTING VALUE OF SELECTED ITEMS FROM BAG
    for(int i=0;i<bags;i++)
    {
        for(int k=0;k<items;k++)
        {
            amountItems[i]=amountItems[i]+choice[k][i+1]*itemPrice[k+1]; 
        }
    }

    // CHECKING IF CAPACITY BAG LESSER THAN SELECTED ITEMS
    for(int i=0;i<bags;i++)
    {
        for(int k=0;k<items;k++)
        {
            amountWeight[i]=amountWeight[i]+choice[k][i+1]*itemWeight[k+1];
        }
    }


    // COMPARING VALUE FROM TABLE BEST CHOICES VS CHOICES FROM BAG
    int otimo, error;
    for(int i=0; i<bags;i++)
    {
    if(amountItems[i]==table[slotsBags[i]][items])
    {
       otimo=1;
    }
    else if(slotsBags[i]<amountWeight[i]){
        error=1;    
    }
    }

    // PRINTING RESULT OF CHOICE ITEMS FROM BAG


    if(otimo==1)
    {
        printf("Solucao otima.\n");
    }
    else if(error==1){
        
        printf("Solucao inviavel.\n");
    }
    else {
    printf("Solucao viavel mas nao otima.\n");
    }
}