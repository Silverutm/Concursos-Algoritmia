#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#define For(x,a,b) for(int x=(a); x<(b); x++)
#define f first
#define s second
#define MP make_pair
using namespace std;

typedef vector <int> vi;

int main()
{
	int C, mat[15][15],arr[500],tot[15],S,N;

	scanf("%d",&C);

	For(c,0,C)
	{
		scanf("%d %d",&N,&S);
		For(j,0,N)
			scanf("%d",&arr[j]), arr[j]--;

		memset(mat,0,sizeof mat);
		memset(tot,0,sizeof tot);

		For(j,0,N-1)
		{
			tot[arr[j]]++;

			mat[arr[j]][arr[j+1]]++;
		}

		For(i,0,S)
		{
			For(j,0,S)
			{
				if(tot[i] > 0)
					printf("%.2lf ",(double)mat[i][j] / (double) tot[i]);
				else
					printf("%.2lf ",(double)mat[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}