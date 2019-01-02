#include <cstdio>
#include <iostream>
#include <string>
#define For(x,a,b) for(int x=(a); x<(b); x++)
using namespace std;

int main()
{
	int C,k;
	string cad;

	scanf("%d",&C);

	For(c,0,C)
	{
		//if(c)printf("\n");

		cin >> k;
		getline(cin,cad);
		getline(cin,cad);

		//printf("%d\n",k);
		For(i,0,cad.size())
		{
			printf("%c ",(cad[i]^k));
		}
		printf("\n");
	}
	return 0;
}