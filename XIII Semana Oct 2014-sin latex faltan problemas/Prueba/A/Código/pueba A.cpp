#include <iostream>
#include <cstdio>
#include <bitset>

#define For(i, a, b) for(int i=a; i<b; ++i)
#define rep(y,z) For(y,0,z)

using namespace std;

string s[105];
bitset <30> gem[105], ans;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);

		rep(i,105) s[i] = "";
		
		For(i, 0, n)
			cin >> s[i];
		
		For(i, 0, n)
			For(j, 0, s[i].size())
				gem[i][s[i][j] - 'a'] = true;
				
		ans = gem[0];
		For(i, 1, n)
			ans &= gem[i];
			
		cout << ans.count() << endl;
	}
	
	return 0;
}