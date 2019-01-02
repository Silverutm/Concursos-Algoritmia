


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; };
int main()
{	
	

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
	
			//////////////////////aqui leo datos e imprimo y todo
            int tt;
            scanf("%d", &tt);

            while (tt--)
            {
                ll a, b;
                scanf("%lld %lld", &a, &b);
                printf("%s\n", gcd(a, b) == 1LL ? "si" : "no");
            }
            

			fclose(stdin);
			fclose(stdout);

		}
	}


	return 0;
}