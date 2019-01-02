#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main()
{

    int a,b;
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    cin>>a>>b;
    while(a+b)
    {
        cout<<a+b<<endl;
        cin>>a>>b;
    }
    return 0;
}
