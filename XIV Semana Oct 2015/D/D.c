#include <stdio.h>
#include <string.h>

#define For(x,a,b) for(unsigned int x = (a); x < (unsigned int)(b); x++)

typedef long long ll;


int main()
{
	int C, n, x;
	double r, tol = 0.2;
	char cad[20];

	scanf("%d",&C);

	while(C--)
	{
		scanf("%d", &n);
		x = 0;
		For(i,0,n){
			scanf("%s", &cad);
			x += (cad[0] == 'n');
		}


		r = (double)x / (double)n;

		if(r < tol)
			printf(":)\n");
		else
			printf("friendzone\n");
	}
	
	return 0;
}