#include <iostream>
#include <cstdio>
#include <algorithm>
#define For(i, a, b) for(int i=a; i<b; ++i)
#define PI 3.14159265359
using namespace std;

struct punto
{
	double x, y, dist;
};

bool myfunction(punto A, punto B){ return A.dist < B.dist; }

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		double Cx, Cy;
		int N, K;
		string basura;
		punto puntos[200];
		cin>>Cx>>Cy>>N>>K;
		For(i, 0, N)
		{
			cin>>puntos[i].x>>puntos[i].y;
			puntos[i].dist = (Cy-puntos[i].y)*(Cy-puntos[i].y) + (Cx-puntos[i].x)*(Cx-puntos[i].x);
		}
		cin>>basura;
		sort(puntos, puntos+N, myfunction);
		printf("%.2f\n",PI*puntos[K-1].dist);
	}
	return 0;
}
