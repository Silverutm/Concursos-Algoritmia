#include<bits/stdc++.h>
using namespace std;

bool palindromo(int i)
{
    stringstream ss; ss<<i;
    string a, b;
    ss>>a;
    b = a; reverse(b.begin(), b.end());
    return a== b;
}

int main()
{
    int cont = 0, hueco =0, res = 0, z=0;

    for (int i=0; i<=1000000; ++i)
        if ( palindromo(i))
        {
            ++cont;
            if (hueco == 1099) ++z;
            res= max(res, hueco);
            hueco = 0;
        }
        else
        {
            ++hueco;
        }
        
    cout<<cont<<"\n"<<res<<"\n"<<z<<"\n";
    return 0;
}