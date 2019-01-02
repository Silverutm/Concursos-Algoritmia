#include <iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while (cin>>x) if (x<1 or x>1000000) cout<<"Nel\n";
	return 0;
}