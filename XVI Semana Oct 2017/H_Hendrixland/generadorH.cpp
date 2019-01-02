#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll intervalo(int a, int b)//////////////ints
{
    return rand()%(b-a+1) + a;      //un numero en [a,b]
}
 
ll rango(int a, int b)      //un numero con esa cantidad de digitos////////////////////longs
{
    ll n = rand()%9 + 1;
 
    int cantidad = intervalo(a, b);
    --cantidad;     //ya tiene un digito
 
    for (int i = 0; i < cantidad; ++i)
    {
        n = 10*n + rand()%10;
    }
    return n;
}
 
int t[3],V[3],A[3];
 
int main()
{
    srand (time(NULL));
    t[0]=100; t[1]=100; t[2]=10;
    V[0]=100; V[1]=1000; V[2]=10000;
    A[0]=1000; A[1]=10000; A[2]=100000;
    char archivo[] = "C1.in";
    for (int caso = 0; caso < 3; ++caso)
    {
        for (char i = '0'; i <= '9'; ++i)
        {
            if (caso==0) archivo[0] = 'C';
            else if (caso==1) archivo[0] = 'M';
            else archivo[0] = 'G';
            archivo[1] = i;
 
            freopen(archivo, "w", stdout);
 
             
             
            int c=intervalo(1,t[caso]-1);
            cout<<c<<"\n";
             
            ll x,y;
            while (c--)
            {
                int v=intervalo(1,V[caso]-1),a=intervalo(1,A[caso]-1);
                cout<<v<<' '<<a<<endl;
                int tope=v;
                while (a--)
                {
                    x = intervalo(1,tope);
                    y = intervalo(1,tope);
                    cout<<x<<" "<<y<<"\n";
                }
            }
 
 
 
 
 
 
            fclose(stdout);
        }
    }
     
    return 0;
}