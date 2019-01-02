#include <iostream>

using namespace std;
main(){
	int n;
	long long a,b;
	cin>>n;
	while(n--)
	{
		cin>>a;
		cin>>b;
		if(a%b==0)
			cout<<a/b<<endl;
		else
			cout<<(a/b)+1<<endl;
	}
}