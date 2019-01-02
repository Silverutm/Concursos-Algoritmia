#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("Reloj.out","w",stdout);
    //freopen("Reloj.in","r",stdin);
    int a,cont=0;
    while(cin>>a)
    {
        cont++;
        cout<<"Caso "<<cont<<": ";
        if(a%6)
        {
            cout<<"N\n";
        }
        else
        {
            cout<<"Y\n";
        }
    }
}
