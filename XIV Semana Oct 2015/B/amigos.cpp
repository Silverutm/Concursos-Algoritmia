#include <iostream>
using namespace std;
int factores[1000][2], i;

void descomponer(int a)
{
    int j =1;
    while (a!=1)
    {
        ++j;
        if (a%j==0)
        {
            ++i;
            factores[i][0]=j;
            while (a%j==0)
            {
                ++factores[i][1];
                a /=j ;
            }
        }
    }
}

int geometrica(int j)
{
    int k, res=1;
    for (k=-1; ++k<=factores[j][1]; )
        res *=factores[j][0];
    --res;
    res /=(factores[j][0]-1);
    return res;
}

int main()
{
    int t, a, b, j,m, res;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        i=-1;

        for (j=-1; ++j<1000; factores[j][1]=0);  //limpiar

        descomponer(a);

        res=1;
        for (j=-1; ++j<=i;)
        {
            res *=geometrica(j);
        }
        res -=a;
        if (res!=b)
            cout<<"Llora desconsoladamente\n";
        else cout<<"Quiza y sin quiza\n";
    }
}
