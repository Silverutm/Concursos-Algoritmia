#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int fact[55];
int main()
{
	fact[0]=1;
	for (int i = 1; i < 52; ++i)
		fact[i] = i * fact[i-1];

	int t, n, m, c;
	cin>>c;

	while (c--)
	{
		cin>>n>>m>>t;
		cout<<t*(n+m)*fact[m+n]/fact[n]/fact[m]<<"\n";
	}
	return 0;
}