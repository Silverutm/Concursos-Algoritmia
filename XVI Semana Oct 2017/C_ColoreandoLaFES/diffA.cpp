#include <bits/stdc++.h>
using namespace std;
int main()
{
    char instruccion[] = "diff C3.outR C3.outR";
    for (int l = 0; l < 2; ++l)  
    {
        for (char k = '0'; k <= '9'; ++k)        
        {
            if (l==0) {instruccion[5] = 'C'; instruccion[13] = 'C';}
            //else if (l==1) {instruccion[5] = 'M'; instruccion[13] = 'M';}
            else {instruccion[5] = 'G'; instruccion[13] = 'G';}
 
            instruccion[6] = k; instruccion[14] = k;           
 
            system(instruccion);
        }
    }
    return 0;
}