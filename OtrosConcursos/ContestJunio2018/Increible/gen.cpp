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
  

int t[3] ={100, 100, 100};
int lim_l[3] = {32, 32, 32};
int lim_c[3] = {2, 32, 32};
  

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
            ll n, col, l;
            while (c--)
            {
                
                    l = intervalo(1, lim_l[caso]);
                    col = intervalo(1, lim_c[caso]);
                    while (l*col > 32)
                    {
                        l = intervalo(1, lim_l[caso]);
                        col = intervalo(1, lim_c[caso]);
                    }
                    cout<<l<<" "<<col<<"\n";                                  
            }
  
  
  
  
  
  
            fclose(stdout);
        }
    }
      
    return 0;
}