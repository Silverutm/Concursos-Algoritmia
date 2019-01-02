#include <iostream>
using namespace std;
int main()
{
	int c, n, m;
	cin>>c;
	while (c--)
	{
		cin>>n>>m;
		cout<<n*(n-1)*m*(m-1)/4<<"\n";
	}
	return 0;
}