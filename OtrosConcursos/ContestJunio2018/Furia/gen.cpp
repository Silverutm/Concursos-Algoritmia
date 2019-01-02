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

  
string rango_cad(int a, int b)      //un numero con esa cantidad de digitos////////////////////longs
{
    ll n = rand()%9 + 1;
    string s = ""; s.push_back(n + '0');
    int cantidad = intervalo(a, b);
    --cantidad;     //ya tiene un digito
  
    for (int i = 0; i < cantidad; ++i)
    {
        //n = 10*n + rand()%10;
        s.push_back('0' + rand()%10);
    }
    return s;
}
  

int t[3] ={100, 100, 10000};
int lim_n[3] = {100, 100000, 900000000};
  

int main()
{

    srand (time(NULL));
    


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
  
              
              
            //int c=intervalo(1,t[caso]-1);
            int c = t[caso];
            cout<<c<<"\n";                          
            ll n, d, a;
            while (c--)
            {
                
                    a = intervalo(1, lim_n[caso]);
                    d = intervalo(1, lim_n[caso]);
                    n = intervalo(1, lim_n[caso]);
                    cout<<a<<" "<<d<<" "<<n<<"\n";                                  
            }
  
  
  
  
  
  
            fclose(stdout);
        }
    }
      
    return 0;
}