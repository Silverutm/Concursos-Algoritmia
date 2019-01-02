#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fib[1000007], n;


int main()
{
	int t;
	fib[1]= fib[2] = 1;
	for (int i = 3; i < 1000005; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2])%9;

	
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
				cin>>n;
				cout<<(fib[n] ? fib[n]:9)<<"\n";
			}

			fclose(stdin);
			fclose(stdout);

		}
	}
	return 0;
}