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

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; 
  }
  int findSet(int i) { 
    return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
  }
  bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j); 
  }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { 
      numSets--; 
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { 
        p[y] = x; setSize[x] += setSize[y]; 
      }
      else { 
        p[x] = y; 
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) 
          rank[y]++; 
      } 
    } 
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<vi> AdjList;

vb vis;

bool dfs(int u, int t)
{
	vis[u] = true;

	if(u == t)
		return true;

	REP(i, AdjList[u].size())
	{
		int v = AdjList[u][i];

		if((not vis[v]) and dfs(v, t))
		{
			return true;
		}
	}

	return false;
}

void solve()
{
	int n;
	scanf("%d", &n);
	DEBUGLN(n);
	assert(n >= 2 and n <= 500);
	int c;
	scanf("%d", &c);
	DEBUGLN(c);
	assert(c >= 2 and c <= n);
	int r;
	scanf("%d", &r);
	DEBUGLN(r);
	//DEBUGLN((n+2-c)*(n+2-c));
	assert(r >= 0 and r <= (n+2-c)*(n+2-c));

	REP(i, n)
	{
		int a;
		scanf("%d", &a);
		assert(a >= 1 and a <= 10000);
	}

	int can;
	//vb bs(n+2, false);
	vi candidatos;


	REP(i, c)
	{
		scanf("%d", &can);
		//bs[can] = true;
		DEBUG(can);
		assert(can >= 1 and can <= n);
		candidatos.push_back(can);
	}
	cerr << "\n";

	UnionFind uf(n+2);
	AdjList.assign(n+2, vi());
	vis.assign(n+2, false);

	REP(i, r)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		assert(u != v);

		assert(u >= -1 and u <= n);
		assert(v >= -1 and v <= n);

		if(u == -1)
			u = n+1;
		if(v == -1)
			v = n+1;

		AdjList[u].push_back(v);
		AdjList[v].push_back(u);

		uf.unionSet(u, v);
	}

	DEBUGLN(uf.numDisjointSets());

	DEBUGLN(dfs(3, 241));

	REP(i, n+2)
	{
		if(uf.findSet(i) == 123)
			DEBUGLN(i);
	}
	REP(i, c)
	{
		FOR(j, i+1, c)
		{

			DEBUG(candidatos[i]);
			DEBUGLN(uf.findSet(candidatos[i]));
			DEBUG(candidatos[j]);
			DEBUGLN(uf.findSet(candidatos[j]));
			DEBUGLN(dfs(candidatos[i], candidatos[j]));
			assert(!dfs(candidatos[i], candidatos[j]));
			//assert(!uf.isSameSet(candidatos[i], candidatos[j]));
		}
	}



}

int main()
{	
	int T;
	scanf("%d", &T);
	assert(T >= 1 and T <= 100);

	REP(i, T)
	{
		DEBUGLN(i);
		solve();
	}

	return 0;
}