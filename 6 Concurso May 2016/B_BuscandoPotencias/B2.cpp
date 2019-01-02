#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    //freopen("B.in","r",stdin);
    //freopen("B.txt","w",stdout);
    int T, n, aux, maxi;
    scanf("%d", &T);
    for(int c = 1; c <= T; c++){
        scanf("%d", &n);
        printf("Caso #%d: ", c);
        if(n % 2)
            printf("(2^0)*%d\n",n);
        else
            maxi = (int)floor(log2(n));
            for(int i = maxi; i > 0; i--){
                if((int)pow(2.0, i) <= n)
                    aux = (n % (int)pow(2, i));
                if(aux == 0){
                    aux = n/(int)pow(2, i);
                    printf("(2^%d)*%d\n", i, aux);
                    break;
                }

            }
    }
    return 0;
}
