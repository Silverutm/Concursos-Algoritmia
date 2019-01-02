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
		validar(n, 1, 10000);
		
				for (int j = 0; j < n; ++j)
				{
					cin>>v;
					validar(v, 1, 10000000000LL);
				}
		
	}
	return 0;
}