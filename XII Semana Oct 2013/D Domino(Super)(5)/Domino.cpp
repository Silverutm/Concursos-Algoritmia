#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int izq[105],der[105];
int n,sumi,sumd;

int main()
{
    freopen("Domino.in","r",stdin);
    freopen("Domino.out","w",stdout);
    int t,cont=0;
    cin>>t;
    while(t--)
    {
        cont++;
        cin>>n;
        cout<<"Caso "<<cont<<": ";
        sumi = sumd = 0;
        bool b = false;
        for(int i=0;i<n;i++)
        {
            cin>>izq[i]>>der[i];
            sumi += izq[i];
            sumd += der[i];
        }
        if((sumi&1) and (sumd&1))
        {
            for(int i=0; i<n; i++)
            {
                if( (izq[i]&1) != (der[i]&1))
                {
                    b = true;
                    break;
                }
            }
            if(b)
                cout<<1<<endl;
            else
                cout<<-1<<endl;
        }
        else if( !(sumi&1) and !(sumd&1) )
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
