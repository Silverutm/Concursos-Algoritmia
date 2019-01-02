#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map< int,vector<int> > lista;
map < int,int > distancia;
 
void ba(int elem)
{
    queue<int> cola;
    cola.push(elem);
    distancia[elem]=0;
    int v;
    while (!cola.empty())
    {
        v=cola.front();
        cola.pop();
        for (auto e: lista[v])
        {
            if (distancia[e]==(-1))
            {
                distancia[e]=distancia[v]+1;
                cola.push(e);
            }
        }
    }
} 
 
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
            bool conectada=true;
            if (!distancia.empty())
                distancia.clear();
            int arista,vertice,a,b;
            cin>>vertice>>arista;
            if (!lista.empty())
                lista.clear();
            for (int i=0;i<arista;i++)
            {
                cin>>a>>b;
                distancia[a]=-1;
                distancia[b]=-1;
                lista[a].push_back(b);
                lista[b].push_back(a);
            }
            ba(b);
    /*        for (auto e: lista)
            {
                cout<<e.first<<' ';
                for (auto f: e.second)
                {
                    cout<<f<<' ';
                }
                cout<<endl;
            }*/
            for (auto e: distancia)
            {
                //cout<<endl<<e.first<<' '<<e.second<<endl;
                if (e.second==(-1))
                {
                    conectada=false;
                    break;
                }
            }
            if (!conectada)
                cout<<"Go to sleep, Mr. Malva."<<endl;
            else
                cout<<"Go, Mr. Malva!"<<endl;
        }
 
            fclose(stdin);
            fclose(stdout);
 
        }
    }
 
 
    return 0;
}