#include <bits/stdc++.h>
#define MAX 100003
 
using namespace std;
typedef long long ll; 

float x[3],y[3];
float m,n,e,f, xin[2],yin[2];

void Cramer();
  
int main()
{
    int T;
    float xm,ym;  
    /*char entrada[] = "ComoTuQuieras0.inR", salida[] = "ComoTuQuieras0.outR";
    for (char ci = '0'; ci <= '9'; ++ci)
    {
        
        entrada[13] = ci; salida[13] = ci;

        freopen(entrada, "r", stdin);
        freopen(salida, "w", stdout);*/
      
        cin>>T;   
        while (T--)
        {
            cin>>x[0]>>y[0];
            cin>>x[1]>>y[1];
            cin>>x[2]>>y[2];

            Cramer();

            xm = ((e*n)-(f*m)) / (n-m);
            ym = (f-e) / (n-m);

            cout<<xm<<" "<<ym<<endl;
        }
  
        /*fclose(stdin);
        fclose(stdout);
    }*/
    return 0;
}
void Cramer()
{
    xin[0] = (x[1]+x[0]) / 2;
    yin[0] = (y[1]+y[0]) / 2;

    xin[1] = (x[2]+x[1]) / 2;
    yin[1] = (y[2]+y[1]) / 2;

    m = (x[0]-x[1])/y[1]-y[0];
    n = (x[1]-x[2])/y[2]-y[1];

    e = yin[0] - (m*xin[0]);
    f = yin[1] - (n*xin[1]);
}