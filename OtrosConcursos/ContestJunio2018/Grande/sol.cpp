//188888881, 777767777, 700666007
//933101339 987101789 996808699 986444689 989646989
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{   
    int t;
    string num;
    bool hayA;
    cin>>t;
    while (t--)
    {
        cin>>num;
        num.push_back('9');
        hayA = false;
        for (int i = 0; i< (int)num.size() - 1; ++i)
            if (num[i]< num[i+1])
            {
                hayA = true;
                num[i] = 'A';
                break;
            }
        num.pop_back();
        if (not hayA)
            num.pop_back();
        for (char c:num)
            if (c!='A') cout<<c;
        cout<<"\n";
    }
    return 0;
}