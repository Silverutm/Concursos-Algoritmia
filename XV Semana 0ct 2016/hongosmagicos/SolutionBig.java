import java.io.*;
import java.util.*;
import java.math.*; 
 
public class SolutionBig{
	public static MyScanner sc = new MyScanner();
	public static PrintWriter out;
	public static PrintWriter err;

	static void solve() {
		int n = sc.nextInt();

		ArrayList<Long> camino = new ArrayList<Long>();
		ArrayList<Long> monedas = new ArrayList<Long>();

		for(int i=0; i < n; i++) {
			camino.add(sc.nextLong());
			monedas.add(0L);
		}
		monedas.add(0L);


		for (int i = 0; i < n; i++) {

			monedas.set(i+1, Math.max(monedas.get(i+1), monedas.get(i)) );
			
			int pos = (int)Math.min((long)i+camino.get(i), (long)n);

			monedas.set(pos, Math.max(monedas.get(pos), monedas.get(i)+camino.get(i)) );
		}

		out.println(monedas.get(n));
	}

	public static void main(String[] args) {	
		out = new PrintWriter(new BufferedOutputStream(System.out));
		err = new PrintWriter(new BufferedOutputStream(System.err));
		// <!--inicio solucion-->
		int n = sc.nextInt();
		while(n-- > 0)
			solve();
		// </!--fin solucion-->
		out.close();
		err.close();
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
