#include <iostream>
using namespace std;

void validar(long long x, long long a, long long b)
{
	if (x<a or x>b) cout<<"Nel\n";
}

int main()
{
	long long x, c, n, v, a, b, q;
	cin>>c;
	while (c--)
	{
		cin>>n;	
		validar(n, 1, 50);
		
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					cin>>v;
					validar(v, 0, 10000000000LL);
				}
			}
		cin>>q;
		validar(q, 1, 100);
		while(q--)
		{
			cin>>a>>b;
			validar(a, 0, n-1);
			validar(b, 0, n-1);
		}
	}
	return 0;
}