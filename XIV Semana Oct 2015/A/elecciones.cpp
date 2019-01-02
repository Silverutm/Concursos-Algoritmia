#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue <int> cola;
int matriz[505][505], votos[505], personas[505];
pair <int, int> candidatos[505];
int infinito=100000000;
int n;

int buscar()
{
    int suma =0, a, i;
    bool ganaste=false, perdiste=false;
    while (!cola.empty() )
    {
        a=cola.front();
        cola.pop();
        if ( personas[a] ) continue;

        if (a==0)   ganaste=true;
        else if (a==n+1) perdiste=true;
        else suma += votos[a];
        personas[a]=1;
        for (i=-1; ++i<=n+1; )
            if (matriz[a][i]==1)
                cola.push(i);
    }
    if (ganaste && !perdiste) suma= infinito;
    if (perdiste && !ganaste) suma =-infinito;
    //cout<<ganaste<<perdiste<<"----"<<suma<<endl;/////////////////
    return suma;
}

int main()
{
    int t, c, r, a, b, i, j;
    cin>>t;
    while (t--)
    {
        cin>>n>>c>>r;

        //limpiar
        while (!cola.empty() ) cola.pop();
        for (i=-1; ++i<=n+1; )
            for (j=-1; ++j<=n+1; )
                matriz[i][j]=0;
        for (i=-1; ++i<=n+1; )
            personas[i]=0;
        for (i=-1; ++i<c; )
            candidatos[i].first=0;
        votos[0]=votos[n+1]=0;

        for (i=0; ++i<=n; )
            cin>>votos[i];

        for (i=-1; ++i<c; )
            cin>>candidatos[i].second;

        while (r--)
        {
            cin>>a>>b;
            if (a==-1) a=n+1;
            if (b==-1) b=n+1;
            //cout<<a<<b<<"....."<<endl;/////////////
            matriz[a][b]=1;
            matriz[b][a]=1;
        }

        for (i=-1; ++i<c; )
        {
            cola.push( candidatos[i].second );
            candidatos[i].first = buscar();
        }

        sort(candidatos, candidatos+c);

        //for (i=-1; ++i<c;)//////////
        //    cout <<candidatos[i].first<<" ";//////////
        //return 0;/////////////

        if (candidatos[c-1].first==infinito  || candidatos[c-2].first==-infinito )
            cout<<candidatos[c-1].second<<endl;
        else
        {
            //contar los no amigos
            int otrasuma=0;
            for (i=0; ++i<=n; )
                if ( personas[i]==0 )
                    otrasuma+=votos[i];
            if ( (candidatos[c-2].first + otrasuma) >= candidatos[c-1].first )
                cout<<"Es mas facil salir de la friendzone que saber quien ganara\n";
            else
                cout<<candidatos[c-1].second<<"'\n";
        }
    }
    return 0;
}
