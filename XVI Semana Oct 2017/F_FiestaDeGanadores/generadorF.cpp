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
  
int t[3],n[3];
ll X[3];
  
int main()
{
    srand (time(NULL));
    t[0]=10; t[1]=10; t[2]=20;
    n[0]=100; n[1]=1000; n[2]=10000;
    X[0]=1000; X[1]=10000000000; X[2]=1000000000000;
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
                ll k=intervalo(1,n[caso]-1);
                cout<<k<<endl;
                while (k--)
                {
                    x = intervalo(1,X[caso]-1);
                    cout<<x;
                    y = intervalo(x++, X[caso]- 1);
                    cout<<" "<<y<<"\n";
                }
            }
  
  
  
  
  
  
            fclose(stdout);
        }
    }
      
    return 0;
}