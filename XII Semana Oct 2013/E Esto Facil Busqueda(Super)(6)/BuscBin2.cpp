#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define For(X,A,B) for(X=A; X<B; X++)
#define Maxt 1000
using namespace std;

int arr[1000]={0};
int var;

void busca(int a,int b,int valor)
{
	if(a == b && arr[b]==valor)
		{var = 1; return;}
	else if(a == b && arr[b]!=valor)
		{var = 0; return;}

	int mitad = (a+b)>>1;

	if(valor <= arr[mitad])
		busca(a,mitad,valor);
	else
		busca(mitad+1,b,valor);
}

int main(int argc, char const *argv[])
{
//    freopen("data.in","r",stdin);
//    freopen("Data.out","w",stdout);
	int i,j,n,casos,sum,tam,x;

	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d",&tam);

		for(i=0; i<tam; i++)
			scanf("%d",&arr[i]);

		scanf("%d",&sum);

		//Cosas
		var = 0;
//		cout<<1<<endl;
		//sort(arr,arr+tam);
		for(int i=0;i<tam-1;i++)
        {
            int aux = i , aux2;
            for(int j=i+1;j<tam;j++)
            {
                if(arr[j] < arr[aux])
                {
                    aux = j;
                }
            }
            aux2 = arr[i];
            arr[i] = arr[aux];
            arr[aux] = aux2;
        }
        ///cout<<2<<endl;
		For(j,0,tam)
		{
			x = sum - arr[j];
			if(x>0)
				busca(0,tam-1,x);

			if(var)
			{
				printf("SI\n");
				break;
			}
		}
		if(var == 0)
			printf("NO\n");
	}
	return 0;
}
