#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n_k(ll n, ll k)
{
	
	
	if (k==n or k==0) return res = 1;

	return res = n_k(n-1, k-1) + n_k(n-1, k);
}

int main()
{	

	ll t, n, m, c;
	cin>>c;
	
	while (c--)
	{
		cin>>n>>m>>t;
		cout<<t*(n+m)*n_k(m+n, n)<<"\n";
	}
	return 0;
}