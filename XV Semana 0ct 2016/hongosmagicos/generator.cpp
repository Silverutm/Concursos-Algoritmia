#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void caso(ll N, ll v1, ll v2, ll v3, ll v4, string archivo)
{
	ll n, a;
	freopen(archivo.c_str(),"w",stdout);
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<ll> disN(1,N), disV1(1, v2), disV2(1, v2), disV3(1, v3), disV4(1, v4);
	srand (time(NULL));
	cout<<100<<endl;
	int c=100, k=0;
	while (c--)
	{		
		n=disN(generator);
		
		if (k==0) a= disV1(generator);
		else if (k==1) a= disV2(generator);
		else if (k==2) a= disV3(generator);
		else if (k==3) a= disV4(generator);
		
		cout<<n<<endl;
	  	cout<<a;
	  	for (int i = 1; i < n; ++i)
	  	{
	  		if (k==0) a= disV1(generator);
			else if (k==1) a= disV2(generator);
			else if (k==2) a= disV3(generator);
			else if (k==3) a= disV4(generator);
	  		cout<<" "<<a;
	  		k = rand()%4;
	  	}
	  	cout<<endl;
	}
}

int main()
{
	
	caso(10,10, 1, 3,100 , "little.in");
	caso(15,5, 8, 100,10000 , "medium.in");
	caso(10000,10, 100, 1000,10000000000LL , "big.in");
	return 0;
}