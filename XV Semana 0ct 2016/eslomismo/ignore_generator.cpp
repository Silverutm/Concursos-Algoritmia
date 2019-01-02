#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll _sieve_size; // ll is defined as: typedef long long ll;
bitset<10000010> bs; // 10^7 should be enough for most cases
vi primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) 
{ // create list of primes in [0..upperbound]
	_sieve_size = upperbound + 1; // add 1 to include upperbound
	bs.set(); // set all bits to 1
	bs[0] = bs[1] = 0; // except index 0 and 1
	for (ll i = 2; i <= _sieve_size; i++) 
		if (bs[i]) 
		{
		// cross out multiples of i starting from i * i!
			for (ll j = i * i; j <= _sieve_size; j += i) 
				bs[j] = 0;
			primes.push_back((int)i); // add this prime to the list of primes
		} 
} // call this method in main method
bool isPrime(ll N) { // a good enough deterministic prime tester
if (N <= _sieve_size) return bs[N]; // O(1) for small primes
for (int i = 0; i < (int)primes.size(); i++)
if (N % primes[i] == 0) return false;
return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2
// inside int main()


ll fp(ll p, ll v4)
{
	ll p1=p;
	for (int i = 0; i < 5 and p<=min(v4, 1000000000LL); ++i)
	{
		p = p*p;
	}
	while (p>v4) p /=p1;
	return p;
}


void caso(ll v0, ll v1, ll v2, ll v3, ll v4, string archivo)
{
	//ll n, a;
	freopen(archivo.c_str(),"w",stdout);
	random_device rd;
	mt19937 generator(rd());

  	//default_random_engine generator;
	uniform_int_distribution<ll> disV0(2,v0), disV1(2, v1), disV2(2, v2), disV3(2, v3), disV4(1, v4);
	srand (time(NULL));
	int c=1000, k=0;
	cout<<c<<endl;	
	ll p, r, m, n, si;
	while (c--)
	{		
		k=rand()%5;
		si = rand()%20;
		//disV2(generator);
		int w=primes.size(); 
		do {p = primes[ rand()%w ]; --w; 
			//if (p>v4) cout<<"p   "<<p<<endl;
			} while (p>v4);

		do { if (k==0) r = disV0(generator);
		else if (k==1) r = disV1(generator);
		else if (k==2) r = disV2(generator);
		else if (k==3) r = disV3(generator);
		else if (k==4) r = disV4(generator); 
			//if (r>v4) cout<<"r   "<<r<<endl;
			} while (r>v4);

		if (si>=8) 
		{
			do { if (k==0) m = disV0(generator);
			else if (k==1) m = disV1(generator);
			else if (k==2) m = disV2(generator);
			else if (k==3) m = disV3(generator);
			else if (k==4) m = disV4(generator); 
				//if (m>v4) cout<<"m   "<<m<<endl;
				} while (m>v4);
		}
		else do{m = fp(p, v4)*(rand()%6+1)-1;
			//if (m>v4) cout<<"m--   "<<m<<endl;
			} while (m>v4);
		
		do { if (k==0) n = disV0(generator);
		else if (k==1) n = disV1(generator);
		else if (k==2) n = disV2(generator);
		else if (k==3) n = disV3(generator);
		else if (k==4) n = disV4(generator); 
			//if (n>v4) cout<<"n   "<<n<<endl;
			} while (n>v4);		

		cout<<p<<" "<<r<<" "<<m<<" "<<n<<endl;
	}	
}

int main()
{
	sieve(10000000);	
	caso(10,50, 100, 500,1000 , "little.in");
	caso(10,100, 1000, 10000,1000000 , "medium.in");
	caso(100,10000, 100000000, 10000000000LL,1000000000000000LL , "big.in");
	return 0;
}