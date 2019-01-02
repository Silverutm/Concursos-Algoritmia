#include <bits/stdc++.h>
 
#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ii;
 
long long dist[155][155];
 
void caso(int N, ll aijp,ll aij, string archivo)
{
    freopen(archivo.c_str(),"w",stdout);
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<ll> disN(1,aij), disNp(1, aijp);
    srand(time(NULL));
    int k=0;
    int tt = 100;
    printf("%d\n", tt);
    while (tt--)
    {
        int n = (rand()%(N-1)) + 2;
        printf("%d\n", n);
 
        For(i, 0, n)
            For(j, i+1, n)
            {
                //int w = (rand()%aij) + 1;
                ll w;
                if (k%2) w=disN(generator);
                else w= disNp(generator);
                k = (k+1)%2;
                dist[i][j] = dist[j][i] = w;
            }
 
        For(i, 0, n)
        {
            For(j, 0, n)
                printf("%lld ", dist[i][j]);
            printf("\n");
        }
 
        int Q = (rand()%100) + 1;
        printf("%d\n", Q);
        while (Q--)
        {
            int a, b, c, d;
            while (true)
            {
                a = rand()%n; b = rand()%n;
                if (a != b )
                    break;
            }
            printf("%d %d\n", a, b);
        }
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    caso(10, 10,100, "little.in");
    caso(20, 100,1000, "medium.in");
    caso(50, 100000000LL, 10000000000LL, "big.in");
    
 
    return 0;
}