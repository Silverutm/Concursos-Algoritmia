#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< pair<int,bool> > hora;
 
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
                if (!hora.empty())
                    hora.clear();
                bool exitoso=true;
                int personas;
                cin>>personas;
                for (int j=0;j<personas;j++)
                {
                    int x,y;
                    pair <int,bool> evento;
                    cin>>x>>y;
                    evento.first=x;
                    evento.second=true;
                    hora.push_back(evento);
                    evento.first=y;
                    evento.second=false;
                    hora.push_back(evento);
                }
                sort(hora.begin(),hora.end());
                int presentes=0,maxpresentes=0;
                for (auto e: hora)
                {
                    if(e.second)
                        presentes++;
                    else
                        presentes--;
                    if (presentes>maxpresentes)
                        maxpresentes=presentes;
                }
                cout<<maxpresentes<<endl;
            }

            fclose(stdin);
            fclose(stdout);
 
        }
    }
 
 
    return 0;
}