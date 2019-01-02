#include <iostream>
#include <cstdio>
#define For(x,a,b) for(int x=a; x<b; x++)
using namespace std;

typedef long long ll;

ll mtres(ll n)
{
	ll r = 3;
	
	for(ll j=6; j<=n; j+=3)
	{
		if((j%5))
			r+=j;
	}
	return r;
}
ll mcinco(ll n)
{
	ll r = 5;
	
	for(ll j=10; j<=n; j+=5)
		r+=j;
	return r;
}

int main()
{
	int T,N;
	
	scanf("%d",&T);
	
	For(j,0,T)
	{
		scanf("%d",&N);
		
		printf("%lld\n",mtres(N-1)+mcinco(N-1));
	}
	return false;
}
