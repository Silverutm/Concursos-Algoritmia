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
    int c=1000, n, m;
    cout<<c<<endl;
    while (c--)
    {
        m = rand()%N+2;
        n = rand()%N+2;
        cout<<m<<" "<<n<<endl;
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    caso(10-1, "little.in");
    caso(100-1, "medium.in");
    caso(10000-1, "big.in");
    
 
    return 0;
}