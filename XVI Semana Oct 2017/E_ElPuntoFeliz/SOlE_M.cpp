//https://web.archive.org/web/20070630095149/http://local.wasp.uwa.edu.au/~pbourke/geometry/circlefrom3/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    char entrada[] = "C1.inR", salida[] = "C1.outM";
    for (int caso = 0; caso <   1; ++caso)
    {
        for (char ci = '0'; ci <= '9'; ++ci)
        {
            if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
            else {entrada[0] = 'G'; salida[0] = 'G';}
            entrada[1] = ci; salida[1] = ci;
 
            freopen(entrada, "r", stdin);
            freopen(salida, "w", stdout);
    
            double x1, x2, x3, y1, y2, y3, ma, mb, x, y;
            int t;
            cin>>t;
            while (t--)
            {
                cin>>x1>>y1;
                cin>>x2>>y2;
                cin>>x3>>y3;
    
                ma = (y2-y1)/(x2-x1);
                mb = (y3-y2)/(x3-x2);
                
                x = (ma*mb*(y1-y3) + mb*(x1+x2) -ma*(x2+x3) )/2/(mb-ma);
                y = -(1/ma)*(x-(x1+x2)/2)+ (y1+y2)/2;
                double d1, d2, d3, h, c1, c2;
                d1 = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
                d2 = sqrt( (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2) );
                d3 = sqrt( (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3) );
    
                h = max(d1, max(d2, d3));
                c1 = min(d1, min(d2, d3));
                c2 = d1+ d2 +d3-h-c1;
                bool aceptado = h != hypot(c1, c2);
    
                printf("%.4lf %.4lf", x, y);
                if (aceptado)
                    printf(" Aceptado\n");
                else printf(" No aceptado\n");
            }

            fclose(stdin);
            fclose(stdout);
        }
    }
    return 0;
}