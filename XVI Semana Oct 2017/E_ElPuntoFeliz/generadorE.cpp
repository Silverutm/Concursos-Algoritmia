#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[3],y[3];
void intervalo();
bool shala();
  
int main()
{
    srand (time(NULL));
    char archivo[] = "ComoTuQuieras0.inR";    
    for (char i = '0'; i <= '9'; ++i)
    {
        archivo[13] = i;
  
        freopen(archivo, "w", stdout);
  
        int T = (rand()%100)+1;
        cout<<T<<endl;
        while(T--)
        {
            intervalo();
            cout<<x[0]<<" "<<y[0]<<endl;
            cout<<x[1]<<" "<<y[1]<<endl;
            cout<<x[2]<<" "<<y[2]<<endl;
        }
             
        fclose(stdout);
    }
    return 0;
}
void intervalo()//////////////ints
{
    x[0] = (rand()%100000000) + 1; 
    y[0] = (rand()%100000000) + 1;
    do
    {
        x[1] = (rand()%100000000) + 1; 
        y[1] = (rand()%100000000) + 1;   
    }
    while(x[0] == x[1] or y[0] == y[1]);
    do
    {
        x[2] = (rand()%100000000) + 1;
        y[2] = (rand()%100000000) + 1;   
    }
    while(!shala());
}
bool shala()
{
    if(x[0] == x[2] or y[0] == y[2])
        return false;
    if(x[1] == x[2] or y[1] == y[2])
        return false;
    if ( (y[1]-y[0]) / (x[1]-x[0]) == (y[2]-y[1]) / (x[2]-x[1]) )
        return false;
    return true;
}
