#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int main()
{
	//std::ios_base::sync_with_stdio(false);

	srand(time(NULL));

	int tt = 100;
	printf("%d\n", tt);
	while (tt--)
	{
		int a = (rand()%100)+1, b = (rand()%100)+1;
		printf("%d %d\n", a, b);
	}

	return 0;
}