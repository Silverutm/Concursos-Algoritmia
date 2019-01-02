#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int dist[55][55];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	srand(time(NULL));

	int tt = 100;
	printf("%d\n", tt);
	while (tt--)
	{
		int n = (rand()%49) + 2;
		printf("%d\n", n);

		For(i, 0, n)
			For(j, i+1, n)
			{
				int w = (rand()%1000) + 1;
				dist[i][j] = dist[j][i] = w;
			}

		For(i, 0, n)
		{
			For(j, 0, n)
				printf("%d ", dist[i][j]);
			printf("\n");
		}

		int Q = (rand()%100) + 1;
		printf("%d\n", Q);
		while (Q--)
		{
			int a, b, c, d;
			while (true)
			{
				a = (rand()%n)+1, b = (rand()%n)+1, c = (rand()%n)+1, d = (rand()%n)+1;
				if (a != b and c != d)
					break;
			}
			printf("%d %d %d %d\n", a, b, c, d);
		}
	}

	return 0;
}