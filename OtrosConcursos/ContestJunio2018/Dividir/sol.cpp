//sacar el numero de primos relativos de 1 a 10**6, ordenar y hacer busquedas binarias sobre la acumulada
//188888881, 777767777, 700666007
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int _sieve_size;
bitset<1020> bs;
vector<int> primes;

void sieve(int upperbound) 
{

    _sieve_size = upperbound + 1;
    bs.set();

    bs[0] = bs[1] = 0;

    for (int i = 2; i <= _sieve_size; i++) 
        if (bs[i]) 
        {
            for (int j = i * i; j <= _sieve_size; j += i) 
                bs[j] = 0;
            primes.push_back(i);
        } 
}

int EulerPhi(int N) 
{
    int PF_idx = 0, PF = primes[PF_idx], ans = N;
    while (PF * PF <= N) 
    {
        if (N % PF == 0) ans -= ans / PF;
        while (N % PF == 0) N /= PF;
        PF = primes[++PF_idx];
    }
    if (N != 1) ans -= ans / N;
    return ans;
}
#define tam 1000001
int prim_rel[tam];
long long acc[tam];
int main()
{
    sieve(1010);
    for (int i = 1; i<tam; ++i)
        prim_rel[i] = EulerPhi(i);
    sort(prim_rel, prim_rel + tam);
    reverse(prim_rel, prim_rel + tam);
    
    acc[0] = prim_rel[0];
    for (int i = 1; i<tam; ++i)
        acc[i] = acc[i - 1] + prim_rel[i];

    //for (int i = 0; i<20; ++i)
    //    cout<<acc[i]<<" ";
    //cout<<"\n";
    //cout<<acc[tam - 1];

    ll t, n;    
    cin>>t;
    while (t--)
    {
        cin>>n;        
        cout<<lower_bound(acc, acc+tam, n) - acc + 1<<"\n";
    }
    return 0;
}

//max valor
//303963552392