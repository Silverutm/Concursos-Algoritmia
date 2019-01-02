import java.io.*;
import java.util.*;
import java.math.*; 
 

public class Amain{
	public static MyScanner sc = new MyScanner();
	public static PrintWriter out;

	// SOLVE

	// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
	class UnionFind {                                              // OOP style
		private Vector<Integer> p, rank, setSize;
		public Vector<Integer> setPowa;
		private int numSets;

		public UnionFind(int N) {
			p       = new Vector<Integer>(N);
			rank    = new Vector<Integer>(N);
			setSize = new Vector<Integer>(N);
			setPowa = new Vector<Integer>(N);

			numSets = N;
			for (int i = 0; i < N; i++) {
				p.add(i);
				rank.add(0);
				setSize.add(1);
				setPowa.add(0);
			}
		}

		public int findSet(int i) { 
			if (p.get(i) == i) 
				return i;
			else {
				int ret = findSet(p.get(i)); p.set(i, ret);
				return ret; 
			} 
		}

		public Boolean isSameSet(int i, int j) { 
			return findSet(i) == findSet(j); 
		}

		public void unionSet(int i, int j) { 
			if (!isSameSet(i, j)) { 
				numSets--; 
				int x = findSet(i), y = findSet(j);
				// rank is used to keep the tree short
				if (rank.get(x) > rank.get(y)) { 
					p.set(y, x); 
					setSize.set(x, setSize.get(x) + setSize.get(y)); 
					setPowa.set(x, setPowa.get(x) + setPowa.get(y)); 
				}
				else { 
					p.set(x, y); 
					setSize.set(y, setSize.get(y) + setSize.get(x));
					setPowa.set(y, setPowa.get(y) + setPowa.get(x));
					if (rank.get(x) == rank.get(y)) 
						rank.set(y, rank.get(y) + 1); 
				} 
			} 
		}

		public int numDisjointSets() { 
			return numSets; 
		}

		public int sizeOfSet(int i) { 
			return setSize.get(findSet(i)); 
		}

		public int powaOfSet(int i) { 
			return setPowa.get(findSet(i)); 
		}
	}

	void solve()
	{
		int n = sc.nextInt();
		int c = sc.nextInt();
		int r = sc.nextInt();

		UnionFind uf = new UnionFind(n+2);
		UnionFind tranza = new UnionFind(n+3);

		uf.setPowa.set(0, 0);
		for (int i = 1; i <= n; i++) {
			uf.setPowa.set(i, sc.nextInt());
		}
		uf.setPowa.set(n+1, 0);

		//out.printf("n: %d c: %d r: %d\n",n, c, r);

		BitSet isCandidate = new BitSet(n+2);

		for(int i = 0; i < c; i++) {
			int ct = sc.nextInt();
			isCandidate.set(ct);
			//out.printf("ct:%d n+2%d\n", ct, n+2);
			tranza.unionSet(ct,n+2);
		}
			

		for(int i = 0; i < r; i++)
		{
			int u = sc.nextInt();
			int v = sc.nextInt();

			u = (u == -1)?n+1:u;
			v = (v == -1)?n+1:v;

			uf.unionSet(u, v);

			tranza.unionSet(u, v);
		}


		int sumFree = 0;
		boolean found = false;
		BitSet counted = new BitSet(n+2);


		for(int i = 1 ; i <= n; i++) {
			if( (!isCandidate.get(i)) && 
				(!counted.get(uf.findSet(i)) ) && 
				(!tranza.isSameSet(i, n+2)) ) {
				//out.printf("i: %d\n", i);
				sumFree += uf.powaOfSet(i);
				counted.set(i);
			}
		}

		
		int idx = -1;

		//out.printf(" sumFree: %d\n", sumFree);

		for(int i = 1 ; i <= n; i++) {
			if( isCandidate.get(i) ) {

				


				if(uf.isSameSet(i, 0) && (!uf.isSameSet(i, n+1)))
				{
					idx = i;
					break;
				}

				if(uf.isSameSet(i, n+1) && (!uf.isSameSet(i, 0)))
				{
					continue;
				}

				boolean exito = true;
				//out.printf("i: %d powi: %d\n", i, uf.powaOfSet(i));
				for(int j = 1; j <= n; j++ ) {
					if(i == j)
						continue;
					//out.printf("\tj: %d powj: %d\n", j, uf.powaOfSet(j));

					if(uf.powaOfSet(i) <= uf.powaOfSet(j)+sumFree &&
					   uf.isSameSet(i, j) == false &&
					   tranza.isSameSet(j, n+2) &&
					   (!(uf.isSameSet(j, n+1) ^  uf.isSameSet(j, 0)))
					) {
						exito = false;
						break;
					}
				}
				if(exito)
					idx = i;
			}
		}

		if(idx == -1)
			out.println("Es mas facil salir de la friendzone que saber quien ganara");
		else
			out.println(idx);

	}

	void run()
	{
		int T = sc.nextInt();
		for (int i=0; i < T; i++ ) {
			solve();
		}

	}


	// !-- SOLVE

	public static void main(String[] args) {
		
		out = new PrintWriter(new BufferedOutputStream(System.out));
		try {
			new Amain().run();	
		}
		catch (Exception e) {
			out.println(e.toString());
		}

		

		out.close();
	}
	  
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} 
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(next());
		}

		BigInteger nextBigInteger(int radix) {
			return new BigInteger(next(), radix);
		}

		String nextLine() {

			String str = "";

			try {
				str = br.readLine();
			} 
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		public boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String line = br.readLine();
					if (line == null) {
						return false;
					}
					st = new StringTokenizer(line);
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}	
			return true;
		}

	}
}
