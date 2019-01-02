#include <bits/stdc++.h>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define INF (1<<30)
#define MP make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		ll n;
		scanf("%lld", &n);

		ll r = sqrt(n);
		printf("%s\n", r*r == n ? "son unos genios" : "les hace falta estudiar");
	}

	return 0;
}