#include <bits/stdc++.h>
 
#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
long long dist[155][155];
 
void caso(int N, string archivo)
{
    freopen(archivo.c_str(),"w",stdout);
    srand(time(NULL));
    int c=1000, p;
    cout<<c<<endl;
    while (c--)
    {
        p=(p+1)%2;
        int k= rand()%N +1;
        cout<<rand()%9+1;
        for (int i = 1; i < k-3; ++i)
            cout<<rand()%10;
        if ( p ) cout<<"784";
        //else ("123");
        cout<<endl;
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    caso(6, "little.in");
    caso(12, "medium.in");
    caso(500, "big.in");
    
 
    return 0;
}