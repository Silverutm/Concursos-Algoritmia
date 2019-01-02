#include <bits/stdc++.h>
using namespace std;

bool is165(string);
 
int main()
{   
    int T;
    string cad_read;
    char entrada[] = "C1.inR", salida[] = "C1.outR";
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
     
            cin>>T;
            while(T--)
            {
                //getline(cin,cad_read);
                cin >> cad_read;
                if (is165(cad_read))
                    cout<<"Descongelar a mi rey."<<endl;
                else
                    cout<<"Dejar descansar a mi rey."<<endl;
            }
 
            fclose(stdin);
            fclose(stdout);
        }
    }
    return 0;
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