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
    freopen("Data.in","r",stdin);
    freopen("Data.out","w",stdout);
    int n,x,v[10]={1,1,2,3,5,8,1,3,4,7};//1123581347
    cin>>n;
    while(n--)
    {
        cin>>x;
        x--;
        printf("%d\n",v[x%10]);
    }
    return 0;
}
