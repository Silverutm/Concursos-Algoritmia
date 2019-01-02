#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

double p[55][2505];

int main()
{
	//std::ios_base::sync_with_stdio(false);
	
	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", n == 1 ? 1 : (n*m - n)/2 + n);
	}

	return 0;
}