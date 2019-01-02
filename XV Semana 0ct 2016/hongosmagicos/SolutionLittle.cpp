#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[10005], tabla[10005];
int n, c;

int respuesta(int i)
{
	if (i>=n ) return 0;
	//if (tabla[i]!=-1) return tabla[i];
	tabla[i] = max ( respuesta(i+1), respuesta(i + arr[i] ) + arr[i] );
	return tabla[i];
}

int main()
{
	cin>>c;
	while (c--)
	{
		memset(tabla, -1, sizeof tabla);
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		int p=respuesta(0);
		//if ( *max_element(arr, arr+n)==p ) cout<<"\n\n\n\nmenso\n\n\n\n";
		//cout<<p<<"    "<<*max_element(arr, arr+n)<<endl;
		cout<<p<<endl;
	}
	return 0;
}