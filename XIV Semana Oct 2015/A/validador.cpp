#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define MP make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int cand[505], s[505], AdjMat[505][505];

int findSet(int i){ return s[i] == i ? i : s[i] = findSet(s[i]); }
void unionSet(int i, int j){ s[findSet(i)] = findSet(j); }

int main()
{

	int tt, caso = 1;
	scanf("%d", &tt);

	assert(tt <= 100);

	while (tt--)
	{
		int n, c, r;
		scanf("%d %d %d", &n, &c, &r);

		//printf("%d %d %d\n", n, c, r);
		assert(2 <= n and n <= 500 and 2 <= c and c <= 500 and 0 <= r and r <= (n+2-c)*(n+2-c));

		For(i, 1, n+1)
		{
			int x;
			scanf("%d", &x);

			assert(1 <= x and x <= 10000);
		}

		For(i, 0, n+2)
			s[i] = i;

		For(i, 0, c)
		{
			scanf("%d", &cand[i]);
			assert(1 <= cand[i] and cand[i] <= n);
		}

		For(i, 0, r)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			assert(-1 <= u and u <= n and -1 <= v and v <= n);

		
			if (u == -1) u = n+1;
			if (v == -1) u = n+1;

			AdjMat[u][v] = AdjMat[v][u] = 1;

			if (findSet(u) != findSet(v))
				unionSet(u, v);
		}

		/*bool visit[505];
		memset(visit, 0, sizeof visit);
		queue <int> cola;
		cola.push(1);
		visit[1] = true;
		while (!cola.empty())
		{
			int u = cola.front(); cola.pop();

			For(v, 0, n+2)
				if (AdjMat[u][v] and !visit[v])
					cola.push(v), visit[v] = true;
		}*/

		For(i, 0, c)
			For(j, i+1, c)
			{
				if (findSet(cand[i]) == findSet(cand[j]))
				{
					printf("caso:%d candidatos %d %d\n", caso, cand[i], cand[j]);
					assert(findSet(cand[i]) != findSet(cand[j]));
				}
			}

		caso++;

	}

	return 0;
}