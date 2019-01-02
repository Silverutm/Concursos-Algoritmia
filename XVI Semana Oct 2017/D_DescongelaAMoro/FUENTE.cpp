#include<stdio.h>

int main()
{
    int long long t,caso, i;
    scanf("%lld", &t);
    for(i=0;i<t; i++)
    {
        scanf("%lld", &caso);
        if(caso%165==0)
        {
            puts("Descongelar a mi rey.\n");
        }
        else
        {
            puts("Dejar descansar a mi rey.\n");
        }
    }
}