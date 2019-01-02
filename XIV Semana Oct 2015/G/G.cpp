#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int dist[55][55], AdjMat[55][55];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		int n;
		scanf("%d", &n);

		For(i, 0, n)
			For(j, 0, n)
				scanf("%d", &AdjMat[i][j]);

		For(i, 0, n)
			For(j, 0, n)
				dist[i][j] = AdjMat[i][j];

		For(k, 0, n)
			For(i, 0, n)
				For(j, 0, n)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		/*For(i, 0, n)
			For(j, 0, n)
				printf("%d%c", dist[i][j], j == n-1 ? '\n' : ' ');
		printf("\n");*/

		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			--a, --b, --c, --d;

			printf("%d\n", min(dist[a][c]+AdjMat[c][d]+dist[d][b], dist[a][d]+AdjMat[d][c]+dist[c][b]));
		}
	}

	return 0;
}