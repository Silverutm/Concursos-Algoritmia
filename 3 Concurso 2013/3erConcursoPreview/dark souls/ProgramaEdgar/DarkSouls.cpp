#include <iostream>
#include <vector> 
#include <cstdio>

using namespace std;

struct pos
{
	int x, y;
	char dir;
};

vector< vector<bool> > v;
int n,m;

void imprimir()
{
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\n";
}

void dragon_fuego(int x, int y, char dir)
{
	if(dir == 'R')
	{
		for(int j=x; j<m; ++j)
		{
			v[y][j] = true;
			if(y-1 >=  0)
				v[y-1][j] = true;
			if(y+1 <  n)
				v[y+1][j] = true;
		}
	}
	else if(dir == 'L')
	{
		for(int j=x; j>=0; --j)
		{
			v[y][j] = true;
			if(y-1 >=  0)
				v[y-1][j] = true;
			if(y+1 <  n)
				v[y+1][j] = true;
		}
	}
	else if(dir == 'D')
	{
		for(int i=y; i<n; ++i)
		{
			v[i][x] = true;
			if(x-1 >=  0)
				v[i][x-1] = true;
			if(x+1 <  m)
				v[i][x+1] = true;
		}
	}
	else if(dir == 'U')
	{
		for(int i=y; i>=0; --i)
		{
			v[i][x] = true;
			if(x-1 >=  0)
				v[i][x-1] = true;
			if(x+1 <  m)
				v[i][x+1] = true;
		}
	}
}

void dragon_electrico(int x, int y, char dir)
{
	if(dir == 'R')
	{
		for(int j=x,i=0; j<m; ++j, ++i)
		{
			v[y][j] = true;
			if(y-i >=  0)
				v[y-i][j] = true;
			if(y+i <  n)
				v[y+i][j] = true;
		}
	}
	else if(dir == 'L')
	{
		for(int j=x,i=0; j>=0; --j,++i)
		{
			v[y][j] = true;
			if(y-i >=  0)
				v[y-i][j] = true;
			if(y+i <  n)
				v[y+i][j] = true;
		}
	}
	else if(dir == 'D')
	{
		for(int i=y,j=0; i<n; ++i,++j)
		{
			v[i][x] = true;
			if(x-j >=  0)
				v[i][x-j] = true;
			if(x+j <  m)
				v[i][x+j] = true;
		}
	}
	else if(dir == 'U')
	{
		for(int i=y,j=0; i>=0; --i,++j)
		{
			v[i][x] = true;
			if(x-j >=  0)
				v[i][x-j] = true;
			if(x+j <  m)
				v[i][x+j] = true;
		}
	}
}

void desicion()
{
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; i < m; ++j)
		{
			if (v[i][j])
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if(flag)
		printf("Escapar\n");
	else
		printf("Pelear\n");
}

void solve()
{
	
	int f, e;
	int x, y;
	char dir;
	//vector<pos> pos_drag;
	//pos dragon;

	scanf("%d %d", &n, &m);
	scanf("%d %d", &f, &e);
	v.resize(n, vector<bool>(m, false));

	for(int i=0; i<f; ++i)
	{
		scanf("%d %d", &x, &y);
		cin >> dir;
		v[y][x] = true;
		dragon_fuego(x, y, dir);
//		imprimir();
	}
	for(int i=0; i<e; ++i)
	{
		scanf("%d %d", &x, &y);
		cin >> dir;
		v[y][x] = true;
		dragon_electrico(x, y, dir);
//		imprimir();
	}

	desicion();

	v.clear();

}

int main()
{
	int casos;

	scanf("%d", &casos);
	for(int i=0; i<casos; ++i)
	{
		solve();

	}

	return 0;
}
