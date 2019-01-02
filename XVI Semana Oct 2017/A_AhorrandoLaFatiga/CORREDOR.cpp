#include <bits/stdc++.h>
using namespace std;


 
int main()
{   
    string entrada = "C1.inR", salidaFUENTE = "C1.outFUENTE", salida = "C1.outR";
    //char ca = 2;
    //cout<<"hola\n";
    for (int caso = 0; caso < 3; ++caso)
    {
        //ca = caso + 'A';
        for (char ci = '0'; ci <= '9'; ++ci)
        {
            if (caso==0) {entrada[0] = 'C'; salida[0] = 'C'; salidaFUENTE[0] = 'C';}
            else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M'; salidaFUENTE[0] = 'M';}
            else {entrada[0] = 'G'; salida[0] = 'G'; salidaFUENTE[0] = 'G'; }
            entrada[1] = ci; salida[1] = ci; salidaFUENTE[1] = ci;
 
            //freopen(entrada.c_str(), "r", stdin);
            //freopen(salida.c_str(), "w", stdout);
            string s = "./A < " + entrada + " > " + salidaFUENTE;
            system(s.c_str());

            string d = "bash -c \"\n echo " + salidaFUENTE +">>basura.in " +" ;diff " + salida + " " + salidaFUENTE + " >> basura.in \" ";//; x=6; echo $x; if [ $x==0 ];\nthen echo " + ca + ">>RES.txt;\nfi\"";
            //cout<<d<<endl;
            system(d.c_str());

            //fclose(stdin);
            //fclose(stdout);
            //cout<<d<<endl;
            //return 0;
        }
    }
    return 0;
}
