#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	int c, p, r, m, n, t;
	cin>>c;
	while(c--)
	{
		cin>>p>>r>>m>>n;
		++m;
		t=0;
		while (m%p==0) {++t; m /= p;}
		if (r <= t*n) cout<<"Lo lograste\n";
		else cout<<"Sad eyes\n";
	}

}