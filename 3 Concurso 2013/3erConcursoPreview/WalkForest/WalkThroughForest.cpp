#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MOD 1000000009
#define For(i, a, b) for(int i = a; i < b; ++i)
using namespace std;

struct nodo
{
	int n;
	int d;
};

int N, M, T;
vector < vector <nodo> > vecino;
int distancia[1000];
int paths[1000];
bool marca[1000];

bool myfunction (nodo i, nodo j) { return (distancia[i.n] < distancia[j.n]); }

void Dijkstra(int inicio)
{
	memset(distancia, -1, sizeof(distancia));
	memset(marca, 0, sizeof(marca));
	distancia[inicio] = 0;

	int n = N;
	while(n--)
	{
		int actual, k;
		for (k=0; k<N; k++)
			if (marca[k] != true and distancia[k] != -1)
			{
				actual = k;
				break;
			}
		for(int j=k; j<N; j++)
			if (distancia[actual] > distancia[j] and distancia[j] != -1 and marca[j] != true)
				actual = j;

		For(i, 0, vecino[actual].size())
			if(distancia[vecino[actual][i].n] > distancia[actual] + vecino[actual][i].d or distancia[vecino[actual][i].n] == -1)
				distancia[vecino[actual][i].n] = distancia[actual] + vecino[actual][i].d;

		marca[actual] = true;
	}
}

int getPaths(int actual)
{
	if (paths[actual] != -1)
		return paths[actual];

	paths[actual] = 0;
	For(i, 0, vecino[actual].size())
		if (vecino[actual][i].n == 1)
			paths[actual] = (paths[actual] + 1)%MOD;
		else if (distancia[vecino[actual][i].n] < distancia[actual])
			paths[actual] = (paths[actual] + getPaths(vecino[actual][i].n)%MOD)%MOD;

	return paths[actual];
}

int main()
{
	freopen("walkforest.in","r",stdin);
	freopen("walkforest.out","w",stdout);
	while(cin>>N>>M and N)
	{
		vecino.assign(N, vector<nodo>());
		T = 0;
		For(i, 0, M)
		{
			int a, b, d;
			nodo nuevo;
			cin>>a>>b>>d;
			nuevo.n = a-1;
			nuevo.d = d;
			vecino[b-1].push_back(nuevo);
			nuevo.n = b-1;
			vecino[a-1].push_back(nuevo);
		}

		Dijkstra(1);

		For(i, 0, N)
			sort(vecino[i].begin(), vecino[i].end(), myfunction);
		memset(paths, -1, sizeof(paths));
		cout<<getPaths(0)<<endl;
	}
	return 0;
}
