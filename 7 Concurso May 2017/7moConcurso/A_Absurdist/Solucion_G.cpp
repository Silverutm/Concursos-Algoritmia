#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll t, n, m, x, k, cuenta;
	
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

			cin>>t;
			while (t--)
			{
				cin>>n>>m>>k;
				cuenta = 0;
				x = max(n, m);
				while(x)
				{
					x >>= 1;
					if ( (n&1) != (m&1) )
						++cuenta;
					n >>= 1; m >>= 1;
				}
				if (cuenta<=k)
					printf("Son compatibles, sean felices por siempre :)\n");
				else printf("Langostas por siempre :(\n");
			}

			fclose(stdin);
			fclose(stdout);

		}
	}
	return 0;
}