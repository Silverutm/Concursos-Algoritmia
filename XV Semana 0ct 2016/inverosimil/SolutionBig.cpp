#include <iostream>
using namespace std;
int main()
{
	long long c, n, m;
	cin>>c;
	while (c--)
	{
		cin>>n>>m;
		cout<<n*(n-1)*m*(m-1)/4<<"\n";
	}
	return 0;
}