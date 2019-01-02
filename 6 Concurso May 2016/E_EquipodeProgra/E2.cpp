#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    //freopen("E.in","r",stdin);
    //freopen("E.txt","w",stdout);
    int T, a, b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d", &a, &b);
        if(a < 4 and b > 6)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
