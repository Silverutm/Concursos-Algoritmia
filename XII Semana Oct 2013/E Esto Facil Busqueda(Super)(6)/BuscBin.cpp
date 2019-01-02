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
    //freopen("Data.in","r",stdin);
    //freopen("Data.out","w",stdout);
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
		sort(arr,arr+tam);
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
