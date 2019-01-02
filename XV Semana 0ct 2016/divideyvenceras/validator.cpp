#include <iostream>
using namespace std;

int main()
{
	long long c;
	cin>>c;
	string x;
	while (c--)
	{
		cin>>x;	
		if (x.size()>500) cout<<"Nel\n";
	}
	return 0;
}