#include <iostream>
using namespace std;
int f[1000009];
int es_palindromo(int n)
{
	int c=n, p;
	p=0;
	while (n)
	{
		p *= 10;
		p += n%10;
		n /= 10;
	}
	return p==c;
}

int main()
{
	int a, n, b,tot;
	cin>>n;
	while (n--)
	{
		cin>>a>>b;
		tot =0;
		for (int i = a; i <= b; ++i)
			tot += es_palindromo(i);
		cout<<tot<<endl;
	}
	return 0;
}