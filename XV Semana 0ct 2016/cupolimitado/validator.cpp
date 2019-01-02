#include <iostream>
using namespace std;

void validar(long long x, long long a, long long b)
{
	if (x<a or x>b) cout<<"Nel\n";
}

int main()
{
	long long x, c, i, f;
	cin>>c;
	while (c--)
	{
		cin>>x;	
		validar(x, 1, 10000);
		while(x--)
		{
			cin>>i>>f;
			validar(i, 1, 1000000000000LL);
			validar(f, 1, 1000000000000LL);
		}
	}
	return 0;
}