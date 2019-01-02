#include <stdio.h>
#include <math.h>

int main()
{
	double PI = atan(1.0)*4.0;
	double R;
	while(scanf("%lf", &R)==1)
	{
		printf("%.4lf\n", (double)PI*R*R);
		printf("%.4lf\n", (double)R*R*2.0);
	}
	return 0;
}
