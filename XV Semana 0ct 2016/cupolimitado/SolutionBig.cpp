#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
pair <ll, ll> arr[10009], actual;
bool f(pair<ll, ll> a, pair<ll, ll> b)
{ return a.second <b.second; }

int main()
{
	int n, c, cant;
	cin>>c;
	while (c--)
	{
		cin>>n;
		actual.first=actual.second=0;
		for (int i = 0; i < n; ++i)
			cin>>arr[i].first>>arr[i].second;
		sort( arr, arr +n , f);
		cant=0;
		for (int i = 0; i < n; ++i)
			if (arr[i].first>=actual.second)
			{
				++cant;
				actual=arr[i];
			}
		cout<<cant<<endl;
	}
	return 0;
}