#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define For(x,a,b) for(unsigned int x = (a); x < (unsigned int)(b); x++)

typedef long long ll;


int main()
{
	int C, n, x;
	double r, tol = 0.2;
	string cad;

	scanf("%d",&C);

	while(C--)
	{
		scanf("%d", &n);
		x = 0;
		For(i,0,n){
			cin >> cad;
			x += cad == "no";
		}


		r = (double)x / (double)n;

		if(r < tol)
			printf(":)\n");
		else
			printf("friendzone\n");
	}
	
	return 0;
}