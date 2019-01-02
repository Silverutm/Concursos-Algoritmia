#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    freopen("Estampas.in","w",stdout);
    srand(time(NULL));
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,cont=0;
        a=(rand()%1000)+10;
        cout<<a<<endl;
        b=rand()%a+1;
        c=rand()%a+1;
        vector<int> v(a+1);
        for(int i=0;i<b;i++)
        {
            d=(rand()%(a+1));
            if(v[d]==0 &&d)
            {
                v[d]=1;
                cont++;
            }
        }
        cout<<cont;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]) cout<<" "<<i;
        }
        cout<<endl;
        vector<int> v1(a+1);
        cont=0;
        for(int i=0;i<c;i++)
        {
            d=(rand()%(a+1));
            if(v1[d]==0 &&d)
            {
                v1[d]=1;
                cont++;
            }
        }
        cout<<cont;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]) cout<<" "<<i;
        }
        cout<<endl;
    }

    return 0;
}

