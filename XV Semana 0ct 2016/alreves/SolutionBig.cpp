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
	int a, n, b;
	f[0]=1;
	for (int i = 1; i < 1000006; ++i)
		f[i] = f[i-1]+ es_palindromo(i);
	cin>>n;
	while (n--)
	{
		cin>>a>>b;
		cout<<f[b]-f[a-1]<<endl;
	}
	return 0;
}