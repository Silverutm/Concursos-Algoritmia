#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <string.h>
#include <set>


using namespace std;

set<string> ananagrama;
vector<string> arr;

bool compare(string a, int apos, string b, int bpos)
{
    if(apos != bpos)
    {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        //cout << a +" "+b+"\n";
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(a == b)
            return true;
        else
            return false;
    }
    return false;

}

int main()
{
    string palabra;



    while((cin >> palabra) and palabra != "#")
    {
        arr.push_back(palabra);
    }

    //vector<bool> isAnan(arr.size(), false);
    bool bandera=false;
    for(int i=0; i<(int)arr.size(); ++i)
    {
        bandera = false;
        for(int j=0; j<(int)arr.size(); ++j)
        {
            if ((bandera = compare(arr[i],i, arr[j],j)) and bandera)
                break;
        }
        if( not bandera)
            ananagrama.insert(arr[i]);
    }
    for(set<string>::iterator  i=ananagrama.begin(); i!=ananagrama.end(); ++i)
    {
        cout << *i << "\n";
    }
    return 0;
}
