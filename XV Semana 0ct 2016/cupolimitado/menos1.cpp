#include <iostream>
using namespace std;
int main()
{
    int t, c;
    long long a, b;
    cin>>t;
    t -= 20;
    cout<<t<<"\n";
    while (t--)
    {
        cin>>c;
        cout<<c<<"\n";
        while (c--)
        {
            cin>>a>>b;
            cout<<a<<" "<<b<<"\n"; 
        }
    }
    return 0;
}