#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;
//ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
//cin.tie(NULL); cout.tie(NULL);


void solve()
{
	string frase, llave;
	getline(cin, frase);
	getline(cin, llave);


	int j = 0;

	//DEBUGLN(frase);
	//DEBUGLN(llave);

	//DEBUGLN((4-22)%26);

	REP(i, frase.size())
	{
		if(frase[i] == ' ')	
			cout << " ";
		else
		{
			char a = frase[i]-'a';
			char b = llave[(j++)%llave.size()]-'a';

			//DEBUG((char)(a+'a'));
			//DEBUGLN((char)(b+'a'));

			cout << (char)((((a-b)+26)%26)+'a');
		}
	}
	cout << '\n';


}

int main()
{
	int T;

	cin >> T;
	string basura;
	getline(cin, basura);

	REP(i, T)
		solve();

	return 0;
}