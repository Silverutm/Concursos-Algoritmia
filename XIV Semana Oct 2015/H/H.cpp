#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; };

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%s\n", gcd(a, b) == 1 ? "si" : "no");
	}

	return 0;
}