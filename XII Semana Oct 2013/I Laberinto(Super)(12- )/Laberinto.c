#include<stdio.h>
char v[50][50];
int a,b;
int dfs(int i,int j)
{
    if(i>0 && j>0 && i<a && j<b && v[i][j]!='#' && (v[i][j]==' ' || v[i][j]=='*'))
    {
        v[i][j]='#';
        dfs(i,j+1);
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
    }
    return 0;
}
int main()
{
    int t,i,k,l;
    char aux[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);//a=filas, b=columnas
        gets(aux);
        for(i=0;i<a;i++)
        {
            gets(v[i]);
        }
        for(k=0;k<a;k++)
        {
            for(l=0;l<b;l++)
            {
                if(v[k][l]=='*')
                {
                    dfs(k,l);
                }
            }
        }
        for(k=0;k<a;k++)
        {
            for(l=0;l<b;l++)
            {
                printf("%c",v[k][l]);
            }
            printf("\n");
        }
    }
    return 0;
}
