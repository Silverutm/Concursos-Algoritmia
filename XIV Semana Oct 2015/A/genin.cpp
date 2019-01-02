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
typedef uniform_int_distribution<int> udist;

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

random_device rd; // obtain a random number from hardware
mt19937 eng(0);//rd()); // seed the generator
udist distn(2, 500);
udist distp(1, 100);
udist dista(1, 10000);

vector<vi> AdjList;
int visited[510][510];



void solve()
{
	int n = distn(eng);

	const int V = n+2;
	int E = 0;
	
	AdjList.assign(V, vi());
	memset(visited, 0, sizeof visited);
	UnionFind uf(V);

	double p = .99;
	DEBUG("\n\n");
	DEBUG(n);
	DEBUG(V);
	DEBUG(uf.numDisjointSets());
	REP(i, V)
	{
		REP(j, V)
		{
			if(visited[i][j] == 0 and visited[j][i] == 0 )
			{
				double q = distp(eng) / 100.0;

				if(q > p and uf.numDisjointSets() >= 3 and i != j)
				{
					//DEBUG(i);
					//DEBUGLN(j);
					AdjList[i].push_back(j);
					//AdjList[j].push_back(i);
					E++;
					uf.unionSet(i, j);
				}
			}
			visited[i][j] = visited[j][i] = 1;
		}
	}

	DEBUG(V);

	DEBUGLN(uf.numDisjointSets());
	DEBUG(n);

	udist distc(2, min((int)uf.numDisjointSets(), n) );
	DEBUG(E);
	DEBUG(min((int)uf.numDisjointSets(), n) );
	int c =distc(eng);
	DEBUGLN(c);
	printf("%d %d %d\n", n, c, E);
	REP(i, n)
	{
		if(i)
			printf(" ");
		printf("%d", dista(eng));
	}
	printf("\n");

	set<int> s;
	udist diste(0, n+1);


	bool flag = false;

	int k = 1;
	while(c > 0 )
	{
		int ct = uf.findSet(k);
		//DEBUG(ct);
		if(s.find(ct) == s.end())
		{
			DEBUG(k);	
			DEBUGLN(ct);

			if(flag)
				printf(" ");
			printf("%d", k);
			s.insert(ct);
			c--;
			flag = true;
		}
		k++;
	}
	printf("\n");




	REP(u, V)
	{
		REP(i, AdjList[u].size())
		{
			int v = AdjList[u][i];
			int _u = u, _v = v;

			// if(_u == bueno)
			// 	_u = 0;
			// else if(_u == 0)
			// 	_u = bueno;

			// if(_v == bueno)
			// 	_v = 0;
			// else if(_v == 0)
			// 	_v = bueno;

			// if(_u == malo)
			// 	_u = -1;
			// else if(_u == n+1)
			// 	_u = malo;

			// if(_v == malo)
			// 	_v = -1;
			// else if(_v == n+1)
			// 	_v = malo;
			

			if(_u == n+1)
				_u = -1;
			if(_v == n+1)
				_v = -1;

			printf("%d %d\n", _u, _v);			
		}
	}

	
}

int main()
{
	int T = 70;
	printf("%d\n", T);

	REP(i, T)
	{
		DEBUGLN(i+1);
		printf("\n");
		solve();
	}



	return 0;
}