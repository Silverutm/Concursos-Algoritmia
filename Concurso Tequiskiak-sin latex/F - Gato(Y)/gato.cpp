#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
//
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<vi> vvi;
#define rep(a,b) for(int a=0;a<b;a++)
#define For(a,b,c) for(int a=b;a<c;a++)
vvi v;
int a,b,res;

void checa_filas()
{
    rep(i,3)
    {
        if(v[i][0] != -1 and v[i][0] == v[i][1] and v[i][1] == v[i][2])
        {
            if(v[i][0] == 1) res = -1;
            else res = 1;
            return;
        }
        if(v[0][i] != -1 and v[0][i] == v[1][i] and v[1][i] == v[2][i])
        {
            if(v[0][i] == 1) res = -1;
            else res = 1;
            return;
        }
    }
}

void checa_columnas()
{
    if(v[1][1] != -1)
    {
        if((v[0][0] == v[1][1] and v[0][0] == v[2][2]) or (v[0][2] == v[1][1] and v[1][1] == v[2][0]))
        {
            if(v[1][1] == 1) res = -1;
            else res = 1;
        }
    }
}

void checa_todo()
{
    checa_filas();
    if(!res) checa_columnas();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int n;
    cin>>n;
    rep(i,n)
    {
        v.assign(3,vi(3,-1));
        res = 0;
        rep(j,9)
        {
            cin>>a>>b;
            if(!res)
            {
                v[a-1][b-1] = (i+j)&1;
                if(j > 2)
                {
                    checa_todo();
                }
            }
        }
        printf("Partida %d: ",i+1);
        if(!res) printf("Empate\n");
        else if(res == 1) printf("David\n");
        else printf("Edgar\n");
    }
}
