#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF (1<<30)
#define MP make_pair
#define MOD 1000000007

using namespace std;

typedef pair <int, int> ii;

int main()
{
	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		long long n;
		scanf("%lld", &n);

		long long a = 2, b = 8;
		For(i, 3, n+1)
		{
			long long c;
			c = ( (4*b) % MOD + a) % MOD;
			a = b;
			b = c;
		}

		printf("%lld\n", n > 1 ? b : a);
	}	

	return 0;
}