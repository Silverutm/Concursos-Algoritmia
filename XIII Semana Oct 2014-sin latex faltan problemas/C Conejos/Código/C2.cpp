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
typedef vector <vector <int> > vvi;

int madd(int a, int b)
{
	return (a + b) % MOD;
}

int mmult(int a, int b)
{
	return (1LL*a*b) % MOD;
}

vvi matmult(vvi A, vvi B)
{
	vvi C(2, vector <int>(2, 0));
	For(i, 0, 2)
		For(j, 0, 2)
			For(k, 0, 2)
				C[i][j] = madd( C[i][j], mmult(A[i][k], B[k][j]) );

	return C;
}

vvi matexp(vvi X, long long n)
{
	if (n == 1)
		return X;

	vvi ans = matexp(X, n >> 1);
	if (n & 1)
		return matmult( matmult(ans, ans), X );

	return matmult(ans, ans);
}

int main()
{
	int tt;
	scanf("%d", &tt);

	while (tt--)
	{
		long long n;
		scanf("%lld", &n);

		if (n == 1)
			printf("2");
		else if (n == 2)
			printf("8");
		else
		{
			vvi X(2, vector <int> (2, 1));
			X[0][0] = 4;
			X[1][1] = 0;

			X = matexp(X, n-2);

			printf("%d\n", madd( mmult(X[0][0], 8), mmult(X[0][1], 2) ) );
		}
	}	

	return 0;
}