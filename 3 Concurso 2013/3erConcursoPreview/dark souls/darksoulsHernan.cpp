#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<vector<bool> > mat;
void dragon_grande(int x, int y, char dir)
{
	if(dir == 'U' or dir == 'D')
	{
		int xi;
		if(dir == 'U')
			xi = -1;
		else
			xi = 1;
		for(int i=x;i<n and i>=0;i+=xi)
		{
			mat[i][y]=false;
			if(y+1<m) mat[i][y+1] = false;
			if(y-1>=0) mat[i][y-1] = false;
		}
	}
	else
	{
		int yi;
		if(dir == 'L')
			yi = -1;
		else
			yi = 1;
		for(int i=y;i<m and i>=0;i+=yi)
		{
			mat[x][i]=false;
			if(x+1<n) mat[x+1][i]=false;
			if(x-1>=0) mat[x-1][i]=false;
		}
	}
}

void dragon_tres(int x, int y, char dir)
{
	if(dir == 'U' or dir == 'D')
	{
		int xi,y1,y2;
		y1 = y2 = y;
		if(dir == 'U')
			xi = -1;
		else
			xi = 1;
		for(int i=x;i<n and i>=0;i+=xi)
		{
			mat[i][y]=false;
			if(y1<m) mat[i][y1] = false;
			if(y2>=0) mat[i][y2] = false;
			y1++;
			y2--;
		}
	}
	else
	{
		int yi,x1,x2;
		x1 = x2 = x;
		if(dir == 'L')
			yi = -1;
		else
			yi = 1;
		for(int i=y;i<m and i>=0;i+=yi)
		{
			mat[x][i]=false;
			if(x1<n) mat[x1][i]=false;
			if(x2>=0) mat[x2][i]=false;
			x1++;
			x2--;
		}
	}
}

bool buscar()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j])
				return true;
	return false;
}
int main()
{
	int dg,dt,t,x,y;
	char c;
	bool b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>dg>>dt;
		mat.assign(n,vector<bool>(m,true));
		while(dg--)
		{
			cin>>x>>y>>c;
			dragon_grande(x,y,c);
		}
		while(dt--)
		{
			cin>>x>>y>>c;
			dragon_tres(x,y,c);
		}
		b = buscar();
		if(b)
			cout<<"Pelear"<<endl;
		else
			cout<<"Escapar"<<endl;
	}
	return 0;
}
