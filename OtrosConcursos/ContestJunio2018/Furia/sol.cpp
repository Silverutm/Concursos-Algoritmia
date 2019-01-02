//188888881, 777767777, 700666007
//933101339 987101789 996808699 986444689 989646989
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 933101339

ll fast_pow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n&1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main()
{   
    int t;
    ll a1, d, n, res;
    cin>>t;
    while (t--)
    {
        cin>>a1>>d>>n;        
        cout<< n * (n+1) % mod * (3 * a1 + d*(n - 1) % mod) % mod * fast_pow(6, mod - 2) % mod<<"\n";
    }
    return 0;
}