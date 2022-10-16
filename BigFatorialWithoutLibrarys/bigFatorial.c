/*
6!
    2*3 = 6 
    v[0]=6                                                                           

   6*4 = 24
    v[0] = resultado%10         -> v[0]=4   
    v[1]= (resultado-v[0]/10)%10 -> v[1]=2       

    24*5 = 120
    v[0]= resultado%10  -> v[0]=0
    v[1]= (resultado-v[0]/10)%10 v[1] = 2
    v[2]= (resultado/10)-v[1]         -> v[2]=1

    120*6=720
    v[0]= 

    // wrong idea
*/