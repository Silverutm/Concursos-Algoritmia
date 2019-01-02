#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v(42);
	int a,cont=0,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v[a%42]=1;
	}
	for(int i=0;i<v.size();i++)
	{
		if(v[i]!=0) cont++;
	}
	cout<<cont<<endl;
	return 0;
}