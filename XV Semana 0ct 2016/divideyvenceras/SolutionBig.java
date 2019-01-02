import java.io.*;
import java.util.*;
import java.math.*; 
 
public class SolutionBig{
	public static MyScanner sc = new MyScanner();
	public static PrintWriter out;
	public static PrintWriter err;
	/*************************************************************/

	public static BigInteger tf = new BigInteger("24");
	static void solve() {
		String s = sc.next();
		BigInteger k = new BigInteger(s);

		if(k.mod(tf) == BigInteger.ZERO)
			out.println("Bien hecho");
		else
			out.println("Next time");
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

	/*************************************************************/

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
