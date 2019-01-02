#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fib[100], n;

int suma(int a)
{
	int res = 0;
	while (a)
	{
		res += a%10;
		a /= 10;
	}
	if (res<10)return res;
	return suma(res);
}

int main()
{
	int t;
	fib[1]= fib[2] = 1;
	for (int i = 3; i < 92; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];

	cin>>t;
	while (t--)
	{
		cin>>n;
		cout<<suma(fib[n])<<"\n";
	}
	return 0;
}