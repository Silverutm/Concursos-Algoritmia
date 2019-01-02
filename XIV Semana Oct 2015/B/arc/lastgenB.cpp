#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



typedef vector<int> vi;
ll _sieve_size;
bitset<10000010> bs;
vi primes;
// compact STL for Sieve, better than vector<bool>!
// ll is defined as: typedef long long ll;
// 10^7 should be enough for most cases
// compact list of primes in form of vector<int>
void sieve(ll upperbound) {
// create list of primes in [0..upperbound]
_sieve_size = upperbound + 1;
// add 1 to include upperbound
bs.set();
// set all bits to 1
bs[0] = bs[1] = 0;
// except index 0 and 1
for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
// cross out multiples of i starting from i * i!
for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
primes.push_back((int)i);
// add this prime to the list of primes
} }


ll sumDiv(ll N) {
ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
// start from ans = 1
while (PF * PF <= N) {
ll power = 0;
while (N % PF == 0) { N /= PF; power++; }
ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
PF = primes[++PF_idx];
}
if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
return ans;
}



ll intervalo(int a, int b)//////////////ints
{
	return rand()%(b-a+1) + a;		//un numero en [a,b]
}

ll rango(int a, int b)		//un numero con esa cantidad de digitos////////////////////longs
{
	ll n = rand()%9 + 1;

	int cantidad = intervalo(a, b);
	--cantidad;		//ya tiene un digito

	for (int i = 0; i < cantidad; ++i)
	{
		n = 10*n + rand()%10;
	}
	return n;
}

int m[3], t[3];

int main()
{
	sieve(10000000);
    srand (time(NULL));	
	t[0]=100; t[1]=1000; t[2]=200;
    m[0]=4; m[1]=8; m[2]=14;
	char archivo[] = "C1.in";
	for (int caso = 0; caso < 3; ++caso)
	{
		for (char i = '0'; i <= '9'; ++i)
		{
			if (caso==0) archivo[0] = 'C';
			else if (caso==1) archivo[0] = 'M';
			else archivo[0] = 'G';
			archivo[1] = i;

			freopen(archivo, "w", stdout);

			
/////////////////////////////////////////						
			cout<<t[caso]<<"\n";
			int w = t[caso];
			ll a, b;
			while(w--)
			{
				a = rango(1,m[caso]);

                int z = intervalo(1,20);
                if (z>8)
				    b = rango(1, m[caso]);
                else
                {
                    b = sumDiv(a) - a;
                    if (b<=0 or b>= pow(10, m[caso]))
                        b = rango(1, m[caso]);
                }
				cout<<a<<" "<<b<<"\n";
			}
//////////////////////////////////////////






			fclose(stdout);
		}
	}
	
	return 0;
}