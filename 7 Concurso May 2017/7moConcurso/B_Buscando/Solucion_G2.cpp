#include <bits/stdc++.h>
using namespace std;

double x[6],y[6];
/////
//suma de angulos opuestos

double d1, d2, a, b, c, d;
double ang1, ang2;
int main()
{
	char entrada[] = "C1.in", salida[] = "C1.outM2";
	for (int caso = 0; caso < 2; ++caso)
	{
		for (char ci = '0'; ci <= '9'; ++ci)
		{
			if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
			else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
			else {entrada[0] = 'G'; salida[0] = 'G';}
			entrada[1] = ci; salida[1] = ci;

			freopen(entrada, "r", stdin);
			freopen(salida, "w", stdout);

			int t;	
			cin>>t;
			while (t--)
			{
				for (int i = 1; i <= 4; ++i)
					cin>>x[i]>>y[i];
				d1 = hypot(x[1]-x[3], y[1]-y[3]);
				d2 = hypot(x[2]-x[4], y[2]-y[4]);

				a = hypot(x[1]-x[4], y[1]-y[4]);
				b = hypot(x[1]-x[2], y[1]-y[2]);
				c = hypot(x[2]-x[3], y[2]-y[3]);
				d = hypot(x[4]-x[3], y[4]-y[3]);

				ang1 =acos( (a*a + d*d - d1*d1)/(2*a*d) );
				ang2 =acos( (b*b + c*c - d1*d1)/(2*b*c) );
						
				if (fabs(ang1+ang2-3.14159)<=1e-4)		
					printf("Schnitzel la acepta.\n");
				else printf("Sigue buscando, Moroni.\n");
			}

			fclose(stdin);
			fclose(stdout);

		}
	}
	return 0;
}