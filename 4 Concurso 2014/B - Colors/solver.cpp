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
    srand(time(NULL));
    freopen("Data.in","r",stdin);
    freopen("Data.out","w",stdout);
    int n,a,b,c;
    string v[8] = {"Negro","Naranja","Verde","Amarillo","Morado","Rojo","Azul","Blanco"};
    cin>>n;
    rep(i,n){
        cin>>a>>b>>c;
        cout<<v[4*a + 2*b + c]<<endl;
    }
    return 0;
}
