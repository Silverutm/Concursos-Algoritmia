#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

vector<vector<int> > cuentitas;
vector<int> niveles;

void recorre(int x, int nivel){
    niveles[x] = nivel;
    if (cuentitas[x].size() > 0)
        for (int i = 0; i < cuentitas[x].size(); i++)
            recorre(cuentitas[x][i], nivel + 1);
}

int main(){
    //freopen("A.in","r",stdin);
    //freopen("A.txt","w",stdout);

    //ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
    //cin.tie(NULL); cout.tie(NULL);

    int T, N;
    int u, v, max_level;
    bool flag;
    cin >> T;
    while(T--){
        max_level = -1;
        flag = false;
        cin >> N;
        cuentitas.assign(N, vector<int>());
        niveles.assign(N, 0);
        for(int i = 0; i < N - 1; i++){
            cin >> u >> v;
            cuentitas[u].push_back(v);
        }
        //Checar si hay mas de uno con cuentas hijas impar
        int cont_odd = 0;
        for(int i = 0; i < N; i++){
            if(cuentitas[i].size() % 2)
                cont_odd++;
            if(cuentitas[i].size() > 2)
                flag = true;
        }
        //cout << "Numero de impares: " << cont_odd << endl;
        recorre(0, 1);
        for(int i = 0; i < N; i++)
            if(niveles[i] > max_level)
                max_level = niveles[i];

        //cout << "Nivel maximo: " << max_level << endl;
        //cout << "Ceil: " << (int)ceil(log2(N));

        if((max_level > (int)ceil(log2(N))) || cont_odd > 1 || flag)
            cout << "Normal" << endl;
        else
            cout << "Especial" << endl;
    }
    return 0;
}
