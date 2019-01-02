//188888881, 777767777, 700666007
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 700666007
#define tam 10005

ll residuos[tam];
ll sumaacc[tam];
void periodo(int a, int b, ll n)
{
    memset(residuos, 0, sizeof residuos);
    memset(sumaacc, 0, sizeof sumaacc);
    int i = 1;
    //printf("0.");                            
    while (not residuos[a]) //no haya aparecido el residuo
    {
        residuos[a] = i;    //a es el primer residuo                
        a = a * 10;         //como a < b, multiplicamos por 10
        sumaacc[i] = a/b + sumaacc[i - 1];
        //printf("%d", a / b);    //imprimimos cuantas veces cabe,xD//////////
        a = a % b;                 //y sacamos el residuo
                                    //a se va sobreescribiendo
        ++i;
    }
    ll ciclo = i - residuos[a];

    //printf("\nEl tamaño del ciclo es %d\n", i - residuos[a]);     ///////
    //cout<<sumaacc[i-1] - sumaacc[residuos[a]-1]<<endl;
    //cout<<sumaacc[residuos[a]-1]<<endl;
    //cout<<residuos[a] - 1<<"\n";
    if (n<i) cout<<sumaacc[n]<<"\n";
    else if (i - residuos[a] == 1 and sumaacc[i-1] - sumaacc[residuos[a]-1] == 0)
    {
        if (n<i) cout<<sumaacc[n]<<"\n";
        else cout<<sumaacc[residuos[a]-1]<<"\n";
    }
    else 
        cout<<( (n - (residuos[a] - 1) )/(i - residuos[a]) % mod * (sumaacc[i-1] - sumaacc[residuos[a]-1]) % mod
             + sumaacc[residuos[a]-1 + (n - (residuos[a] - 1) )%(i - residuos[a]) ]  )%mod <<"\n";
}

int main()
{
    ll n;
    int t, a, b;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>n;
        periodo(a, b, n);
    }
    return 0;
}
/*
56 987
35 789
1 456
192982456140350877
00219298245614035087719298245614035087719298245614035087719298245614035
*/