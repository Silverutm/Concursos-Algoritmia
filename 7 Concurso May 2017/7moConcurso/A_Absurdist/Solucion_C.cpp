#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t, n, m, x, k, cuenta;
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
	return 0;
}