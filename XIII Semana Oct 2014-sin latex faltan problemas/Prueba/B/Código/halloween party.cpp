#include<iostream>
#include<cstdio>
using namespace std;
#define rep(a,b) for(int a=0; a<(int)b; a++)
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<(n/2)*(n - n/2)<<endl;
	}
	return 0;
}