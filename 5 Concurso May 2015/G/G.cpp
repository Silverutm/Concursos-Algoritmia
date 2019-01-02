#include <bits/stdc++.h>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define INF (1<<30)
#define MP make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int a[100005];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		memset(a, 0, sizeof a);

		int n, m;
		scanf("%d %d", &n, &m);

		bool ok = true;
		For(i, 0, n*m)
		{
			int x;
			scanf("%d", &x);
			a[x]++;
			if (a[x] > n)
				ok = false;
		}

		printf("%s\n", ok ? "si" : "no");
	}

	return 0;
}