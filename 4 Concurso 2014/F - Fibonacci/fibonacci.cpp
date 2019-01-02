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
int main()
{
    std::ios_base::sync_with_stdio(false);
    freopen("Data.in","w",stdout);
    printf("20\n");
    rep(i,20)
    {
        printf("%d\n",((int)2)<<i);
    }
    return 0;
}
