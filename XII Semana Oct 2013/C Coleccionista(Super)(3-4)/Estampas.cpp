#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    freopen("Estampas.in","r",stdin);
    freopen("Estampas.out","w",stdout);
    int estampas,aux,tengo,desinteres,cont1,cont2,cont=0;;
    vector<int> yatengo;
    vector<int> nomeinteresan;
    while(cin>>estampas)
    {
        cont1=0;
        cont2=0;
        cont++;
        yatengo.assign(estampas+1,0);
        nomeinteresan.assign(estampas+1,0);
        cin>>tengo;
        for(int i=0;i<tengo;i++)
        {
            cin>>aux;
            yatengo[aux]=1;
        }
        cin>>desinteres;
        for(int i=0;i<desinteres;i++)
        {
            cin>>aux;
            nomeinteresan[aux]=1;
        }
        for(int i=1;i<estampas+1;i++)
        {
            if(nomeinteresan[i]==0 && yatengo[i]==0)
            {
                cont1++;
            }
        }
        cout<<cont1;
        for(int i=1;i<estampas+1;i++)
        {
            if(nomeinteresan[i]==0 && yatengo[i]==0)
            {
                cout<<" "<<i;
            }
        }
        cout<<endl;
        for(int i=1;i<estampas+1;i++)
        {
            if(nomeinteresan[i]==1 && yatengo[i]==1)
            {
                cont2++;
            }
        }
        cout<<cont2;
        for(int i=1;i<estampas+1;i++)
        {
            if(nomeinteresan[i]==1 && yatengo[i]==1)
            {
                cout<<" "<<i;
            }
        }
        cout<<endl;
    }
    return 0;

}
