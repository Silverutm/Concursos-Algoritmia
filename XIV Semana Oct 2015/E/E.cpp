#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

ii p[105];

bool ccw(ii A, ii B, ii C)
{
	return (B.x-A.x)*(C.y-A.y) - (B.y-A.y)*(C.x-A.x) >= 0;
}

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
			scanf("%d %d", &p[i].x, &p[i].y);

		ii f;
		scanf("%d %d", &f.x, &f.y);

		bool sgn = ccw(f, p[0], p[1]), ok = true;
		For(i, 1, n)
			if (ccw(f, p[i], p[(i+1)%n]) != sgn)
			{
				ok = false;
				break;
			}

		printf("%s\n", ok ? "si" : "no");
	}

	return 0;
}