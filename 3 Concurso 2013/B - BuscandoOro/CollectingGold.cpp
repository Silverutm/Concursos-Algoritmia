#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#define For(i, a, b) for(int i=a; i<b; ++i)
using namespace std;

struct punto
{
	int x, y;
};

struct nodo
{
	string S;
	int pos[20];
};

int tabla[30][35000];
nodo I[35000];
int dist[30][30], N = 1;
map <string, int> Ind;

int max(int a, int b)
{
	return a > b ? a : b;
}

void getSubStrings(int t, int x, int n, int* pos, string A)
{
	A = A + (char)(x+'0');
	if (t == n)
	{
		Ind[A] = *pos;
		I[*pos].S = A;
		For(k, 1, A.length())
		{
			string B = A;
			int u = int(B[k]-'0');
			B.replace(k, 1, "");
			I[*pos].pos[u] = Ind[B];
		}
		(*pos)++;
		return;
	}

	for( ; x < N-1; x++)
		getSubStrings(t+1, x+1, n, pos, A);
}

void iniTabla()
{
	int pos = 0;
	For(i, 0, N)
		getSubStrings(0, 0, i, &pos, "");
}

void HamCycle()
{
	For(i, 0, N)
		tabla[i][0] = dist[i][0];

	For(j, 1, 1<<(N-1))
	{
		For(i, 0, N)
		{
			if (j == (1<<(N-1))-1 and i) return;
			int min = -1;
			For(k, 1, I[j].S.length())
			{
				int u = int(I[j].S[k]-'0'), S_u = I[j].pos[u];
				if (tabla[u][S_u] + dist[u][i] < min or min == -1)
					min = tabla[u][S_u] + dist[u][i];
			}
			tabla[i][j] = min;
		}
	}
}

int main()
{
	//freopen("entrada.in","r",stdin);
	punto pos[20];
	string mundo[20];
	int T;
	cin>>T;
	For(casos, 0, T)
	{
		int R, C;
		cin>>R>>C;
		For(i, 0, R)
			cin>>mundo[i];
		For(i, 0, R)
			For(j, 0, C)
				if (mundo[i][j] == 'x')
				{
					pos[0].x = j;
					pos[0].y = i;
				}
				else if (mundo[i][j] == 'g')
				{
					pos[N].x = j;
					pos[N].y = i;
					N++;
				}
		For(i, 0, N)
			For(j, i+1, N)
				dist[i][j] = dist[j][i] = max(abs(pos[i].x - pos[j].x), abs(pos[i].y - pos[j].y));

		iniTabla();
		HamCycle();
		cout<<"Case "<<casos+1<<": "<<tabla[0][(1<<(N-1))-1]<<endl;
		Ind.clear();
		N = 1;
	}
	return 0;
}
