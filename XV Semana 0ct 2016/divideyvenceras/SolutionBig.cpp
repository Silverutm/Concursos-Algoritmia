#include <iostream>
using namespace std;
int main()
{
	int c, tot;
	cin>>c;
	string x;
	bool posible;
	while (c--)
	{
		cin>>x;
		x = "00" + x;
		tot=0;
		posible = true;
		for (auto e:x)
			tot += e-'0';
		if (tot%3) posible=false;
		tot = (x[x.size()-1]-'0') +(x[x.size()-2]-'0')*10 + (x[x.size()-3]-'0')*100;
		if (tot%8) posible=false;
		if(posible) cout<<"Bien hecho\n";
		else cout<<"Next time\n";
	}
	return 0;
}