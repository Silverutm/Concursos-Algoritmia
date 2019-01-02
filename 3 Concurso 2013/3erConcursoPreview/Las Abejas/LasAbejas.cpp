#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cmath>
#define For(i, a, b) for (int (i) = int(a); i < int(b); (i)++)
#define PI 3.14159265359

using namespace std;

//const double PI = 4*atan(1.0);

void solve()
{
	int n, k;
	
	double x, y, ox, oy;

	scanf("%lf %lf", &ox , &oy);
	scanf("%d %d", &n, &k);
	vector<double> distancia(n,0.0);
	for(int i=0; i<n; ++i)
	{
		scanf("%lf %lf", &x, &y);
		double xi, yi;
		xi = x-ox;
		yi = y-oy;
		distancia[i] = sqrt(xi*xi+yi*yi);
	}
	sort(distancia.begin(), distancia.end());

	printf("%.2lf\n", distancia[k-1]*distancia[k-1]*PI );

	while(getchar() != '*');

}

int main()
{	
	int casos;

	scanf("%d", &casos);

	for(int i=0; i<casos; i++)
	{
		solve();
	}
}
