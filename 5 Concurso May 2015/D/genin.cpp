#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int main()
{
	//std::ios_base::sync_with_stdio(false);
	
	srand(time(NULL));

	int tt = 97;
	printf("%d\n", tt+3);

	while (tt--)
	{
		int n = (rand() % 50) + 1, m = (rand() % 50) + 1;
		printf("%d %d\n", n, m); 
	}

	return 0;
}