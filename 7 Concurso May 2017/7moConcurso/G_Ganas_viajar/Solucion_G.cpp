#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p1, p2, p3, f, t, c1,c2,c3;
char e;

int main()
{
	int c;	
	char entrada[] = "C1.in", salida[] = "C1.outM";
	for (int caso = 0; caso < 3; ++caso)
	{
		for (char ci = '0'; ci <= '9'; ++ci)
		{
			if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
			else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
			else {entrada[0] = 'G'; salida[0] = 'G';}
			entrada[1] = ci; salida[1] = ci;

			freopen(entrada, "r", stdin);
			freopen(salida, "w", stdout);

			cin>>c;
			while (c--)
			{
				cin>>n;
				cin>>p1>>p2>>p3>>f;
				c1= c2=c3=0;
				for (int i = 0; i < n; ++i)		
				{
					cin>>e>>t;
					if (e=='S')
					{
						if (t > f)
							++c3;
					}
					else			
						if (t<f) ++c1;			
				}
				c2 = n/2 - c1 - c3;
				cout<<p1*c1 + p2*c2 + p3*c3<<"\n";
			}
			fclose(stdin);
			fclose(stdout);

		}
	}
	return 0;
}