#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
pair <ll, ll> arr[100009], actual;
bool f(pair<ll, ll> a, pair<ll, ll> b)
{ return a.second <b.second; }

int main()
{
	int n, c, cant;
	
	char entrada[] = "C1.in", salida[] = "C1.outM";
	for (int caso = 0; caso < 3; ++caso)
	{
		for (char ci = '0'; ci <= '9'; ++ci)
		{
			if (caso==0) {entrada[0] = 'C'; salida[0] = 'C';}
			else if (caso==1) {entrada[0] = 'M'; salida[0] = 'M';}
			else {entrada[0] = 'G'; salida[0] = 'G';}
			entrada[1] = ci; salida[1] = ci;

			freopen(entrada, "r", stdin);
			freopen(salida, "w", stdout);

			cin>>c;
			while (c--)
			{
				cin>>n;
				actual.first=actual.second=0;
				for (int i = 0; i < n; ++i)
					cin>>arr[i].first>>arr[i].second;
				sort( arr, arr +n , f);
				cant=0;
				/*for (int i = 0; i < n; ++i)
				{
					//cout<<arr[i].first<<" "<<arr[i].second<<endl;
				}*/
				for (int i = 0; i < n; ++i)
					if (arr[i].first>=actual.second)
					{
						++cant;
						actual=arr[i];
						//cout<<arr[i].first<<" "<<arr[i].second<<endl;
					}
				cout<<cant<<endl;
			}

			fclose(stdin);
			fclose(stdout);

		}
	}
	return 0;
}