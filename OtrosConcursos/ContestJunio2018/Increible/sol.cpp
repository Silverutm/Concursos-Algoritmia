#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tabla[35][35], largo, colores, res, potencia[35][35];
map<int, bool> mapa;
int bracalete;

void f(int l)
{
    if (l == largo)
    {
        //sacar las rotaciones y ver si rifa
        if (mapa[bracalete]) return ;
        ++res;
        int copia = bracalete;
        for (int i=0; i< largo; ++i)
        {
            mapa[copia] = true;
            int residuo = copia % colores;
            copia = copia / colores + residuo * potencia[colores][largo - 1];
        }
        return ;
    }
    for (int c = 0; c< colores; ++c)
    {
        //bracalete.push_back(c);
        bracalete = bracalete * colores + c;
        f(l + 1);
        bracalete = bracalete / colores;
    }

}

int main()
{       
    int t;
    for (colores = 1; colores <=32; ++colores) potencia[colores][0] = 1;
    for (colores = 1; colores <=32; ++colores)
        for (largo = 1; largo<=32; ++largo)
            potencia[colores][largo] = potencia[colores][largo - 1] * colores;

    for (largo = 1; largo<=32; ++largo)
        for (colores = 1; colores <=32; ++colores)
        {
            if (largo * colores > 32) continue;
            mapa.clear();
            bracalete = 0;
            res = 0;
            f(0);
            tabla[largo][colores] = res;
        }

    cin>>t;
    while (t--)
    {
        cin>>largo>>colores;
        cout<<tabla[largo][colores]<<"\n";
    }
    return 0;
}