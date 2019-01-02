#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
int main()
{
    int T;
    ll n,k;

    char entrada[] = "C1.inR", salida[] = "C1.outR";
    for (int caso = 0; caso < 2; ++caso)
    {
        for (char ci = '0'; ci <= '9'; ++ci)
        {
            if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
            else {entrada[0] = 'G'; salida[0] = 'G';}
            entrada[1] = ci; salida[1] = ci;
 
            freopen(entrada, "r", stdin);
            freopen(salida, "w", stdout);
     
            cin>>T;   
            while (T--)
            {
                cin>>n>>k;
                cout<<(ll)ceil((ld)n/(ld)k)<<endl;
            }
 
            fclose(stdin);
            fclose(stdout);
        }
    }
    return 0;
}