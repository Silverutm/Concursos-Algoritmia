#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("Reloj.in","w",stdout);
    int a;
    for(int i=0;i<100;i++)
    {
        a = rand()%181;
        cout<<a<<endl;
    }
}
