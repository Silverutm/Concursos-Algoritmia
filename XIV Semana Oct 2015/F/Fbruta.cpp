#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

double p[15], P[15];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		For(i, 0, n)
			For(j, 0, m)
			{
				int a;
				scanf("%d", &a);

				p[i] += a == 0 ? 0 : 1/(double)(m*a);
			}

		For(i, 1, (1 << n))
		{
			int ppl = __builtin_popcount(i);
			double prob = 1.0;

			For(j, 0, n)
				if (i & (1 << j))
					prob *= p[j];
				else
					prob *= 1-p[j];

			P[ppl] += prob;
		}

		double E = 0.0;
		For(i, 1, n+1)
		{
			E += i*P[i];
			printf("%d: %.2lf\n", i, P[i]);
		}

		printf("%.2lf\n", E);
	}

	return 0;
}