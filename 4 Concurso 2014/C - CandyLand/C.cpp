#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define INF (1<<30)

using namespace std;

int v[1000005];

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N, K;
		scanf("%d %d", &N, &K);

		int res = -INF, ind = 1;
		For(i, 1, N+1)
		{
			scanf("%d", &v[i]);
			v[i] += v[i-1];
		}

		For(i, K, N+1)
			if (v[i] - v[i-K] > res)
				res = v[i]-v[i-K], ind = i-K+1;

		printf("%d %d\n", ind, res);
	}

	return 0;
}