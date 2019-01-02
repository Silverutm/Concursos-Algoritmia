#include <bits/stdc++.h>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define INF (1<<30)
#define MP make_pair
#define MOD 1000000007
typedef long long ll;
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

ll C[205][205], v[30];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	For(i, 0, 201)
		For(j, 0, i+1)
			C[i][j] = i == j or j == 0 ? 1 : (C[i-1][j] + C[i-1][j-1]) % MOD;

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		memset(v, 0, sizeof v);
		
		char s[205];
		scanf("%s", s);

		int n = strlen(s);
		For(i, 0, n)
			v[s[i]-'a']++;

		ll ans = 1;
		For(i, 0, 'z'-'a'+1)
		{
			if (v[i] > 0)
				ans = (ans*C[n][v[i]]) % MOD;
			n -= v[i];
		}

		printf("%lld\n", ans);
	}

	return 0;
}