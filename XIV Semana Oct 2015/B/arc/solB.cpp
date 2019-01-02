


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


int main()
{	
	sieve(10000000);
    //cout<<primes[primes.size()-1]<<endl;
    //return 0;

	char entrada[] = "C1.in", salida[] = "C1.outM";
	for (int caso = 0; caso < 3; ++caso)
	{
		for (char ci = '0'; ci <= '9'; ++ci)
		{
			if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
			else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
			else {entrada[0] = 'G'; salida[0] = 'G';}
			entrada[1] = ci; salida[1] = ci;

			freopen(entrada, "r", stdin);
			freopen(salida, "w", stdout);
	
			//////////////////////aqui leo datos e imprimo y todo
            int tt;
            scanf("%d", &tt);

            while (tt--)
            {
                ll a, b;
                scanf("%lld %lld", &a, &b);
                
                ll res = sumDiv(a) - a;
                if (res!=b)
                    cout<<"Llora desconsoladamente\n";
                else cout<<"Quiza y sin quiza\n";
            }
            

			fclose(stdin);
			fclose(stdout);

		}
	}


	return 0;
}