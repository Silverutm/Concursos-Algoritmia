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

vector<vector<int> > AdjList;

int mini_leaf, maxi_leaf;

bool bt(int u, int level)
{


	if(AdjList[u].size() < 2)
	{
		// DEBUGLN(level);
		mini_leaf = min(mini_leaf, level);
		maxi_leaf = max(maxi_leaf, level);
	}
	else if (AdjList[u].size() > 2)
	{
		return false;
	}

	bool is_binary = true;
	REP(i, AdjList[u].size())
	{
		int v = AdjList[u][i];

		is_binary &= bt(v, level+1);
	}

	return is_binary;
}

void solve()
{
	int N;

	scanf("%d", &N);
	//DEBUGLN(N);

	AdjList.assign(N, vector<int>());

	REP(i, N-1)
	{
		int u, v;

		scanf("%d %d", &u, &v);
		//DEBUG(u);
		//DEBUGLN(v);

		assert(u >= 0 and u < N);
		assert(v >= 0 and v < N);

		AdjList[u].push_back(v);
	}

	//DEBUGLN(N);

	mini_leaf = INF, maxi_leaf = 0;

	bool is_binary = bt(0, 0);

	// DEBUG(mini_leaf);
	// DEBUGLN(maxi_leaf);

	if(is_binary and maxi_leaf - mini_leaf <= 1 )
		printf("Especial\n");		
	else
		printf("Normal\n");
}

int main()
{
	int T;
	scanf("%d", &T);

	REP(i, T)
		solve();

	return 0;
}