#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int votos[505], cand[505], total[505];
bool visit[505];
vector <vector <int> > AdjList;

int main()
{

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		memset(total, 0, sizeof total);
		memset(visit, 0, sizeof visit);

		int n, c, r;
		scanf("%d %d %d", &n, &c, &r);

		AdjList.assign(n+2, vector <int> ());

		For(i, 1, n+1)
			scanf("%d", &votos[i]);

		For(i, 0, c)
			scanf("%d", &cand[i]);

		For(i, 0, r)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			if (u == -1) u = n+1;
			if (v == -1) v = n+1;

			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		For(i, 0, c)
		{
			queue <int> cola;
			cola.push(cand[i]);
			visit[cand[i]] = true;

			bool malo = false, bueno = false;
			while (!cola.empty())
			{
				int u = cola.front(); cola.pop();

				if (u == n+1) malo = true;
				else if (u == 0) bueno = true;
				else total[cand[i]] += votos[u];					

				For(j, 0, (int)AdjList[u].size())
				{
					int v = AdjList[u][j];
					if (visit[v])
						continue;

					cola.push(v);
					visit[v] = true;
				}
			}

			if (malo and !bueno) total[cand[i]] = -INF;
			if (bueno and !malo) total[cand[i]] = INF;
		}

		int maxi1 = -INF, maxi2 = -INF, ganador, resto = 0;
		For(i, 1, n+1)
		{
			//printf("%d: %d\n", i, total[i]);
			if (total[i] > maxi1)
				maxi2 = maxi1, maxi1 = total[i], ganador = i;
			else if (total[i] > maxi2)
				maxi2 = total[i];
		
			if (!visit[i])
				resto += votos[i];
		}

		//printf("%d %d\n", maxi1, maxi2);

		if (maxi2 + resto < maxi1)
			printf("%d\n", ganador);
		else
			printf("Es mas facil salir de la friendzone que saber quien ganara\n");

	}

	return 0;
}