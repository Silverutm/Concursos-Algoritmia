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
  

int t[3] ={10, 10, 100};
int lim_n[3] = {15, 1000, 10000};
int lim_x[3] = {3, 5, 7};

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
  
              
                          
            int c = t[caso];
            cout<<c<<"\n";                          
            ll n;
            while (c--)
            {
                
                    n =  lim_n[caso];
                    cout<<n<<"\n";
                    for (int k = 0; k< n-1; ++k)
                        cout<<rango(1, lim_x[caso])<<" ";     //x_i                                  
                    cout<<rango(1, lim_x[caso])<<"\n";
            }
  
  
  
  
  
  
            fclose(stdout);
        }
    }
      
    return 0;
}