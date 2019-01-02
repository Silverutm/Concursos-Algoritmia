#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
vector<string> v;
int dfs(int i,int j)
{
    if(i>0 && j>0 && j<v[i].size() && i <v.size() && v[i][j]!='#' && (v[i][j]==' ' || v[i][j]=='*'))
    {
        v[i][j]='#';
        dfs(i,j+1);
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
    }
    return 0;
}
int main()
{
    freopen("Laberinto.in","r",stdin);
    freopen("Laberinto.out","w",stdout);
    string aux;
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;//a=filas, b=columnas
        getline(cin,aux);
        for(int i=0;i<a;i++)
        {
            getline(cin,aux);
            v.push_back(aux);
        }
        for(int k=0;k<v.size();k++)
        {
            for(int l=0;l<v[k].size();l++)
            {
                if(v[k][l]=='*')
                {
                    dfs(k,l);
                }
            }
        }
        for(int k=0;k<v.size();k++)
        {
            cout<<v[k]<<endl;
        }
        cout<<endl;
        v.clear();
    }
    return 0;
}
