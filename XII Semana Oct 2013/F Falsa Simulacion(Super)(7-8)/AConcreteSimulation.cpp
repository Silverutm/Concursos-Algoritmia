#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

#define N 1234
#define M 5678

vi rows(N+3, 0);
vi cols(M+3, 0);
vi rr = rows;
vi cc = cols;

void solveR()
{
	int x, y;
	scanf("%d %d", &x, &y);
	swap( rows[x], rows[y] );
	rr[rows[x]] = x;
	rr[rows[y]] = y;
}

void solveC()
{
	int x, y;
	scanf("%d %d", &x, &y);
	swap( cols[x], cols[y] );
	cc[cols[x]] = x;
	cc[cols[y]] = y;
}

void solveQ()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", ((rows[x]-1) * M) + cols[y] );
}

void solveW()
{
	int z;
	cin >> z;
	--z;
	printf("%d %d\n", rr[(z / M)+1], cc[(z%M)+1]);
}

int main()
{
	for (int i = 0; i < M+3; ++i)
	{
		cc[i] = cols[i] = i;
	}
	for (int i = 0; i < N+3; ++i)
	{
		rr[i] = rows[i] = i;
	}
	char orden;
	while(cin >> orden)
	{
		switch(orden)
		{
			case 'R':
				solveR();
				break;
			case 'C':
				solveC();
				break;
			case 'Q':
				solveQ();
				break;
			case 'W':
				solveW();
				break;
		}
	}
	return 0;
}
