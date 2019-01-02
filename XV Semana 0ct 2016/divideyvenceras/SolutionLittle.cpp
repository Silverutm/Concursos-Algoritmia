#include <iostream>
using namespace std;
int main()
{
	int c, tot;
	cin>>c;
	int x;
	bool posible;
	while (c--)
	{
		cin>>x;
		posible = true;
		if (x%24)posible=false;
		if(posible) cout<<"Bien hecho\n";
		else cout<<"Next time\n";
	}
	return 0;
}