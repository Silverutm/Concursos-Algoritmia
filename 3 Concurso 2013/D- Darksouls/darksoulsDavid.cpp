#include <iostream>
#include <cstring>
#define For(i, a, b) for(int i=a; i<b; ++i)
#define FOR(i, a, b) for(int i=a; i>b; --i)
using namespace std;

bool mundo[35][35];
int N, M;

void fuego(int x, int y, char d)
{
	if (d == 'U')
		FOR(i, y, -1)
		{
			mundo[i][x] = 1;
			if (x-1 >= 0) mundo[i][x-1] = 1;
			if (x+1 < M) mundo[i][x+1] = 1;
		}
	else if (d == 'D')
		For(i, y, N)
		{
			mundo[i][x] = 1;
			if (x-1 >= 0) mundo[i][x-1] = 1;
			if (x+1 < M) mundo[i][x+1] = 1;
		}
	else if (d == 'L')
		FOR(i, x, -1)
		{
			mundo[y][i] = 1;
			if (y-1 >= 0) mundo[y-1][i] = 1;
			if (y+1 < N) mundo[y+1][i] = 1;
		}
	else
		For(i, x, M)
		{
			mundo[y][i] = 1;
			if (y-1 >= 0) mundo[y-1][i] = 1;
			if (y+1 < N) mundo[y+1][i] = 1;
		}
}

void electrico(int x, int y, char d)
{
	mundo[y][x] = 1;
	if (d == 'U')
	{
		FOR(i, y-1, -1) mundo[i][x] = 1;
		for(int i=y-1, j=x-1; i >= 0 and j >= 0; i--, j--) mundo[i][j] = 1;
		for(int i=y-1, j=x+1; i >= 0 and j < M; i--, j++) mundo[i][j] = 1;
	}
	if (d == 'D')
	{
		For(i, y+1, N) mundo[i][x] = 1;
		for(int i=y+1, j=x-1; i < N and j >= 0; i++, j--) mundo[i][j] = 1;
		for(int i=y+1, j=x+1; i < N and j < M; i++, j++) mundo[i][j] = 1;
	}
	if (d == 'L')
	{
		FOR(i, x-1, -1) mundo[y][i] = 1;
		for(int i=y-1, j=x-1; i >= 0 and j >= 0; i--, j--) mundo[i][j] = 1;
		for(int i=y+1, j=x-1; i < N and j >= 0; i++, j--) mundo[i][j] = 1;
	}
	if (d == 'R')
	{
		For(i, x+1, M) mundo[y][i] = 1;
		for(int i=y-1, j=x+1; i >= 0 and j < M; i--, j++) mundo[i][j] = 1;
		for(int i=y+1, j=x+1; i < N and j < M; i++, j++) mundo[i][j] = 1;
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int F, E;
		cin>>N>>M>>F>>E;
		
		For(i, 0, N)
			memset(mundo[i], 0, sizeof(mundo[i]));
		
		For(i, 0, F)
		{
			char d;
			int x, y;
			cin>>y>>x>>d;
			fuego(x, y, d);
		}
		For(i, 0, E)
		{
			char d;
			int x, y;
			cin>>y>>x>>d;
			electrico(x, y, d);
		}
		bool escapar = false;
		For(i, 0, N)
			For(j, 0, M)
				if (!mundo[i][j])
					escapar = true;
					
		if (!escapar)
			cout<<"Escapar"<<endl;
		else
			cout<<"Pelear"<<endl;
	}
	return 0;
}
