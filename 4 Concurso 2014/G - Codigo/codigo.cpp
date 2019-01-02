#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
    freopen("Data.in","r",stdin);
    freopen("Data.out","w",stdout);
    int t,m,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        cin>>s;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                cout<<s[i+m*j];
            }

        }
        cout<<endl;
    }

    return 0;
}
