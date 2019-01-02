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
		For(i, 0, N)
			scanf("%d", &v[i]);

		For(i, 0, N-K+1)
		{
			int sum = 0;
			For(j, 0, K)
				sum += v[i+j];

			if (sum > res)
			{
				res = sum;
				ind = i+1;
			}
		}


		printf("%d %d\n", ind, res);
	}

	return 0;
}