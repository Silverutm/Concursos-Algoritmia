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

int N;

int per[100005];

int myrand(int minimum_number, int max_number)
{
	return rand() % (max_number + 1 - minimum_number) + minimum_number;
}

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

  void resize(int N) {
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

UnionFind uf(100000);
vector< vector<bool> > AdjMat;
vector< vector<int> > AdjList;
vector<bool> visited;

void bt(int u)
{

	visited[u] = true;

	REP(i, AdjList[u].size())
	{
		int v = AdjList[u][i];

		if(u != v and (not visited[v]))
		{
			printf("%d %d\n", u, v);
			bt(v);
		}
	}
}

void genRan()
{
	N = myrand(1, 100000-1);
	per[0] = 0;
	visited.assign(N, false);
	FOR(i, 1, N)
	{
		per[i] = i;
	}

	FOR(i, 1, N)
	{
		swap( per[i], per[myrand(i, N-1)] );
	}	
	

	printf("%d\n", N);

	uf.resize(N);
	AdjMat.assign(N, vector<bool> (N, false));
	AdjList.assign(N, vi());

	while(uf.numDisjointSets() > 1)
	{
		int u = myrand(0, N-1);
		int v = myrand(0, N-1);

		if(u != v and (not AdjMat[u][v]) and (not uf.isSameSet(u, v)) )
		{
			uf.unionSet(u, v);
			AdjMat[u][v] = AdjMat[v][u] = true;

			AdjList[per[u]].push_back(per[v]);
			AdjList[per[v]].push_back(per[u]);
		}
	}



	bt(0);
}

void genBin()
{
	N = myrand(1, 100000-1);
	per[0] = 0;
	FOR(i, 1, N)
	{
		per[i] = i;
	}

	FOR(i, 1, N)
	{
		swap( per[i], per[myrand(i, N-1)] );
	}


	printf("%d\n", N);

	REP(u, N)	
	{
		int v;

		v = u+u+1;
		if(v < N)
			printf("%d %d\n", per[u], per[v]);

		v = u+u+2;
		if(v < N)
			printf("%d %d\n", per[u], per[v]);
	}
}

int main()
{
	int T = 95;

	printf("%d\n", T);

	REP(i, T)
	{
		
		if(myrand(0, T) % 3 == 0)
			genBin();
		else
			genRan();
	}

}