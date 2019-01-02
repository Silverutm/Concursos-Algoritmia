#include <iostream>
using namespace std;
int main()
{
    long long t, n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        if (n%165) cout<<"Dejar descansar a mi rey.\n";
        else cout<<"Descongelar a mi rey.\n";
    }
    return 0;
}