#include <bits/stdc++.h>
#define MAX 100003

using namespace std;
typedef long long ll;

ll tabla[MAX];
void llena_tabla();
 
int main()
{
    llena_tabla();
    int T,a;  
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
            while (T--)
            {
                cin>>a;
                cout<<tabla[a-1]<<endl;
            }
 
            fclose(stdin);
            fclose(stdout);
        }
    }
    return 0;
}
void llena_tabla()
{
    tabla[0]=3; tabla[1]=8;
    for (int i = 2; i < MAX; ++i)
        tabla[i]= (2*(tabla[i-1]+tabla[i-2]) % 1000000007);
}