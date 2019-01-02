#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

 
int main()
{   
     
 
    string entrada = "C1.in", salida = "C1.out";
    for (int caso = 0; caso < 3; ++caso)
    {
        for (char ci = '0'; ci <= '9'; ++ci)
        {
            if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
            else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
            else {entrada[0] = 'G'; salida[0] = 'G';}
            entrada[1] = ci; salida[1] = ci;
            
            ///////////////////////////////////////////////////////////////////////////
            //string comando = "python mipy.py < " + entrada + " > " + salida;
            //string comando = "./compiladoc < " + entrada + " > " + salida;            
            //system("javac miclasemasdlas.java");
            //system("g++ -std ")
            string comando = "./sol < " + entrada + " > " + salida;            
            system(comando.c_str());

        }
    }
 
 
    return 0;
}
