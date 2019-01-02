//188888881, 777767777, 700666007
//933101339 986444689
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 986444689
#define tam 100001

int primos[] = {0, 2, 5, 7, 11, 17};

ll tabla[tam][6];
ll f(int n, int i)
{
    if (n < 0) return 0;
    if (n == 0) return 1;

    auto &res = tabla[n][i];
    if (~res) return res;
    res = 0;
    for (int j = 1; j<=5; ++j)
        if (j != i)
            res = ( res + f(n - primos[j], j) ) % mod;
    return res;
}

int main()
{   
    memset(tabla, -1, sizeof tabla);
    int t, n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<f(n, 0)<<"\n";
    }
    return 0;
}