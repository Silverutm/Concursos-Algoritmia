#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int m[3];

string intervalo(int);
string genera_multiplo(int);
bool is165(string);
 
int main()
{
    srand (time(NULL));
    m[0]=5; m[1]=15; m[2]=50; //cota maxima
    char archivo[] = "C1.inR";
    
    for (int caso = 0; caso < 3; ++caso)
    {
        for (char i = '0'; i <= '9'; ++i)
        {
            if (caso==0) archivo[0] = 'C';
            else if (caso==1) archivo[0] = 'M';
            else archivo[0] = 'G';
            archivo[1] = i;
 
            freopen(archivo, "w", stdout);
 
            int T;
            if(caso == 0 or caso == 1)
                T=1000;
            else
                T=100;
            cout<<T<<endl;
            while(T--)
            {
                if(T%8 == 0 or T%13 == 0 or (((rand()%9) + 1) + 0) == 3 )
                    cout<<genera_multiplo(m[caso])<<endl;
                else
                    cout<<intervalo(m[caso])<<endl;   
            }
            fclose(stdout);
        }
    }
    return 0;
}
string intervalo(int a)//////////////////////////////genera strings de numeros
{
    string cad_retorno;
    for (int i = 0; i < a; ++i)
        cad_retorno.push_back(((rand()%9) + 1) + '0');
    return cad_retorno; 
}
string genera_multiplo (int a)
{
    string cad;
    do
    {
        cad=intervalo(a);
    }
    while(is165(cad) == false);
    return cad;
}
bool is165 (string cad_read)
{
    int mult3=0,mult11=0,mult11_2=0,tam=(int)cad_read.size();
    if(cad_read[tam-1] != '0' and cad_read[tam-1] != '5')
        return false;
    for (int i=0;i< tam;i++)
    {
        int aux=cad_read[i]-'0';
        mult3+=aux;
        if (i%2)
            mult11_2+=aux;
        else
            mult11+=aux;
    }
    if((mult11 - mult11_2)%11)
        return false;
    if (mult3%3)
        return false;
    return true;
}