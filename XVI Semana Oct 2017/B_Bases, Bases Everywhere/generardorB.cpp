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
  
string convertir_base(ll nuevo_n,ll nuevo_b){
 
 
    char dato_correspondiente[17];
    dato_correspondiente[0]='0';
    dato_correspondiente[1]='1';
    dato_correspondiente[2]='2';
    dato_correspondiente[3]='3';
    dato_correspondiente[4]='4';
    dato_correspondiente[5]='5';
    dato_correspondiente[6]='6';
    dato_correspondiente[7]='7';
    dato_correspondiente[8]='8';
    dato_correspondiente[9]='9';
    dato_correspondiente[10]='A';
    dato_correspondiente[11]='B';
    dato_correspondiente[12]='C';
    dato_correspondiente[13]='D';
    dato_correspondiente[14]='E';
    dato_correspondiente[15]='F';
    dato_correspondiente[16]='G';
 
    string cadena;
 
    ll residuo,resl=1;
    while(resl!=0){
 
        resl=nuevo_n/nuevo_b;
        residuo=nuevo_n%nuevo_b;
        nuevo_n=resl;
 
        cadena.push_back(dato_correspondiente[residuo]);
 
    }
 
    return cadena;
 
 
}
  
int main()
{
 
    ll n,b;
    srand (time(NULL));
    char archivo[] = "B1.in";
    for (int caso = 0; caso < 3; ++caso)
    {
        for (char i = '0'; i <= '9'; ++i)
        {
            if (caso==0) archivo[0] = 'C';
            else if (caso==1) archivo[0] = 'M';
            else archivo[0] = 'G';
            archivo[1] = i;
  
            freopen(archivo, "w", stdout);
  
              
              
            int t=1000;
            cout<<t<<"\n";
              
 
            while(t--)
            {
                b=intervalo(11,16);
                if (caso==2)
                    n= rango(10,15);
                else n=intervalo(1,100000000);
 
 
 
                string cadena=convertir_base(n,b);
 
                for(int p=cadena.size()-1; p>=0;  p--)
                    cout<<cadena[p];
                cout<<" "<<b<<"\n";
 
 
            }
  
  
  
  
  
  
            fclose(stdout);
        }
    }
}