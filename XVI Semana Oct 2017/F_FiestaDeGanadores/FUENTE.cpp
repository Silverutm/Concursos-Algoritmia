#include<stdio.h>
#include<stdlib.h>
int contarGentes();
int main()
{
    int n,i,res[10];
    scanf("%d",&n);

    for (int i=0; i<n;i++)
        res[i]=contarGentes();

    for (int i=0; i<n;i++)
    printf("%d\n",res[i]);

    return 0;
}
int contarGentes()
{
    int *apuntador[2],*cuenta;
    int n,i,masgrande,aux=0,j,aux2=0;
    scanf("%d",&n);
    apuntador[0]=((int*)malloc(n*sizeof(int)));
    apuntador[1]=((int*)malloc(n*sizeof(int)));

    for(i=0;i<n;i++){
        scanf("%d",&apuntador[0][i]);
        scanf("%d",&apuntador[1][i]);

        if(apuntador[1][n]>aux);
            aux=apuntador[1][n];
    }
    cuenta=(int*)malloc((1000)*sizeof(int));

    for(i=0;i<n;i++){
        int pivote1=1+apuntador[0][i];
        int pivote2=apuntador[1][i];
        for(j=pivote1;j<=pivote2;j++)
        {
            cuenta[j]++;
        }
    }
    for(i=0;i<=n;i++){
        if(cuenta[i]>aux2){
            aux2=cuenta[i];
        }
    }
    delete(apuntador[0]);
    delete(apuntador[1]);

    return aux2;
}