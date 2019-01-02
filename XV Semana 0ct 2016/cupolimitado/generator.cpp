#include <bits/stdc++.h>
 
#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
long long dist[155][155];
 
void caso(int N, ll c,ll g,string archivo)
{
    ll m= (g+c)/2;
    freopen(archivo.c_str(),"w",stdout);
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<ll> disV1(1, c), disV2(1, m), disV3(1, g);
    srand(time(NULL));
    int t=100;
    cout<<t<<endl;
    ll a, b;
    int p;
    while (t--)
    {
        int k= rand()%N +1;
        cout<<k<<endl;
        for (int i = 0; i < k; ++i)        
        {
            do
            {
                p=rand()%6;
                if (p==0)
                {
                    a = disV1(generator);
                    b = disV1(generator);
                }
                else if (p==1)
                {
                    a = disV2(generator);
                    b = disV2(generator);
                }
                else if (p==2)
                {
                    a = disV3(generator);
                    b = disV3(generator);
                }
                else if (p==3)
                {
                    a = disV1(generator);
                    b = disV2(generator);
                }
                else if (p==4)
                {
                    a = disV1(generator);
                    b = disV3(generator);
                }
                else if (p==5)
                {
                    a = disV2(generator);
                    b = disV3(generator);
                }

                if (b<a) swap(a,b);
            } while (b==a);
            cout<<a<<" "<<b<<endl;
        }
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    caso(100,100,100000, "little.in");
    caso(100, 100,10000000000LL,"medium.in");
    caso(10000, 100,1000000000000LL,"big.in");
    
 
    return 0;
}