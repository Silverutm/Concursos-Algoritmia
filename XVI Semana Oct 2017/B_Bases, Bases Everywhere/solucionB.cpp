#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <char,int> numeros;
map <int, char> inversa;


 
 
int main()
{   
    
    numeros['1']=1;
    numeros['2']=2;
    numeros['3']=3;
    numeros['4']=4;
    numeros['5']=5;
    numeros['6']=6;
    numeros['7']=7;
    numeros['8']=8;
    numeros['9']=9;
    numeros['0']=0;
    numeros['A']=10;
    numeros['B']=11;
    numeros['C']=12;
    numeros['D']=13;
    numeros['E']=14;
    numeros['F']=15;
    numeros['G']=16;

    inversa[1] = '1';
    inversa[2] = '2';
    inversa[3] = '3';
    inversa[4] = '4';
    inversa[5] = '5';
    inversa[6] = '6';
    inversa[7] = '7';
    inversa[8] = '8';
    inversa[9] = '9';
    inversa[10] = 'A';
    inversa[11] = 'B';
    inversa[12] = 'C';
    inversa[13] = 'D';
    inversa[14] = 'E';
    inversa[15] = 'F';
    inversa[16] = 'G';
    

    long long t,suma_10=0;
    int aa=0,b;
    string n;




 
    char entrada[] = "C1.in", salida[] = "C1.outP";
    for (int caso = 0; caso < 3; ++caso)
    {
        for (char ci = '0'; ci <= '9'; ++ci)
        {
            if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
            else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
            else {entrada[0] = 'G'; salida[0] = 'G';}
            entrada[1] = ci; salida[1] = ci;
 
            freopen(entrada, "r", stdin);
            freopen(salida, "w", stdout);
     
            //////////////////////aqui leo datos e imprimo y todo

            
            cin>>t;
            while(t--){
                cin>>n>>b;
        
                for(int p=n.size()-1;p>=0; p--){
                    
                    suma_10=suma_10+(numeros[n[p]]*(pow(b,aa)));
                    aa++;
                 
                }

                if(suma_10%(b-1)==0)
                    cout<<inversa[(b-1)]<<"\n";
                        
                else
                    cout<<inversa[suma_10%(b-1)]<<"\n";
                
                suma_10=0;
                aa=0;




            }

 
            fclose(stdin);
            fclose(stdout);
 
        }
    }
 
 
    return 0;
}