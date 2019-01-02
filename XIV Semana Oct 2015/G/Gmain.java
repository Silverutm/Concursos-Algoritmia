import java.io.*;
import java.util.*;
import java.math.*; 
 

class book implements Comparable<book> {
	private Calendar tiempo;
	private int tipo;

	public book(Calendar tiempo, int tipo) {
		this.tiempo = tiempo;
		this.tipo = tipo;
	}

	public int getTipo() {
		return this.tipo;
	}

	public int compareTo(book o) {
		return this.tiempo.compareTo(o.tiempo);
	}
}

public class Gmain{
	public static MyScanner sc = new MyScanner();
	public static PrintWriter out;

	// SOLVE

	int[][] AdjMat = new int[51][51];
	int[][] OriMat = new int[51][51];

	void solve()
	{
		int N = sc.nextInt();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				AdjMat[i][j] = OriMat[i][j] = sc.nextInt();
			}
		}

		for(int k = 0; k < N; k++)
		{
			for(int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++ ) 
				{
					AdjMat[i][j] = Math.min(AdjMat[i][j], AdjMat[i][k]+AdjMat[k][j]);
				}
			}
		}


		int Q = sc.nextInt();

		for(int q = 0; q< Q; q++)
		{
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			a--;
			b--;
			c--;
			d--;

			out.println(Math.min(
				AdjMat[a][c] + OriMat[c][d] + AdjMat[d][b],
				AdjMat[a][d] + OriMat[d][c] + AdjMat[c][b]
			));
		}
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

		new Gmain().run();

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
