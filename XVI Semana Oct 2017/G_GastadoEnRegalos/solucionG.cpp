#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <int,bool> da;
map <int,bool> recibe;
 
int main()
{   
     
 
    char entrada[] = "C1.in", salida[] = "C1.outM";
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

            int casos;
            cin>>casos;
            for (int i=0;i<casos;i++)
            {
                if (!da.empty())
                    da.clear();
                if (!recibe.empty())
                    recibe.clear();
                bool exitoso=true;
                int personas;
                cin>>personas;
                for (int j=0;j<personas;j++)
                {
                    int x,y;
                    cin>>x>>y;
                    if (da[x] or recibe[y] or x==y)
                        exitoso=false;
                    else
                    {
                        da[x]=true;
                        recibe[y]=true;
                    }
                }
                if (exitoso)
                {
                    cout<<"Intercambio exitoso."<<endl;
                }
                else
                {
                    cout<<"Papelitos otra vez."<<endl;
                }
            }

            fclose(stdin);
            fclose(stdout);
 
        }
    }
 
 
    return 0;
}