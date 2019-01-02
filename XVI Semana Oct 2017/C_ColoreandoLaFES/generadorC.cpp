#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll m[3];

ll intervalo(ll, ll);
 
int main()
{
    srand (time(NULL));
    m[0]=10000; m[1]=1000000000000000LL; //cota maxima
    char archivo[] = "C1.inR";
    
    for (int caso = 0; caso < 2; ++caso)
    {
        for (char i = '0'; i <= '9'; ++i)
        {
            if (caso==0) archivo[0] = 'C';
            else archivo[0] = 'G';
            archivo[1] = i;
 
            freopen(archivo, "w", stdout);
 
            int T=1000;
            cout<<T<<endl;
            while(T--)
            {
                if ((((rand()%9) + 1) + 0) == 7 or T%13 == 0)
                    cout<<intervalo(1,m[caso])<<" "<<((rand()%99) + 1)<<endl;  
                cout<<intervalo(1,m[caso])<<" "<<intervalo(1,m[caso])<<endl;   
            }
            fclose(stdout);
        }
    }    
    return 0;
}
ll intervalo(ll a, ll b)
{
    return rand()%(b-a+1) + a;      //un numero en [a,b]
}