#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

int matriz[1000][1000], N, M, visitados;
bool visitado[1000], conexo = false;

void DFS(int actual)
{
	visitados++;
	visitado[actual] = true;
	if (visitados == N) conexo = true;
	
	For(i, 0, 1000)
		if (matriz[actual][i] != 0 and visitado[i] == false)
			DFS(i);
}

int main()
{
	freopen("walkforest.in","w",stdout);
	int T = 10;
	srand(time(NULL));
	
	For(i, 0, T)
	{
		N = (rand()%1000)+1; M = (rand()%((N*(N-1))/2))+1;
		do{
			For(j, 0, N)
				memset(matriz[j], 0, sizeof(matriz[j]));
			memset(visitado, 0, sizeof(visitado));
			visitados = 0;
			conexo = false;
			For(j, 0, M)
			{
				int x, y;
				do{
					x = rand()%N; y = rand()%N;
				}while(x == y or matriz[y][x] != 0 or matriz[x][y] != 0);
				matriz[y][x] = (rand()%1000)+1;
			}
			DFS(0);
		}while(!conexo);
		cout<<N<<" "<<M<<endl;
		For(j, 0, N)
			For(k, 0, N)
				if (matriz[j][k] != 0)
					cout<<j+1<<" "<<k+1<<" "<<matriz[j][k]<<endl;
	}
	cout<<0<<endl;
	return 0;
}
