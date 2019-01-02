#include <iostream>
#include <cstdio>
#define For(x,a,b) for(int x=a; x<b; x++)
using namespace std;

typedef long long ll;

ll mtres(ll n){ll r = n/3; return (r*(r+1)/2)*3;}
ll mcinco(ll n){ll r= n/5; return (r*(r+1)/2)*5;}
ll mquince(ll n){ll r= n/15; return (r*(r+1)/2)*15;}

int main()
{
	int T,N;
	
	scanf("%d",&T);
	
	For(j,0,T)
	{
		scanf("%d",&N);
		
		printf("%lld\n",mtres(N-1)+mcinco(N-1)-mquince(N-1));
	}
	return false;
}
