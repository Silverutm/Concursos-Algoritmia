import java.io.*;
import java.util.*;
import java.math.*; 
 
public class SolutionBig{
	public static MyScanner sc = new MyScanner();
	public static PrintWriter out;
	public static PrintWriter err;

	

	static void solve() {
		int a = sc.nextInt();
		int p = sc.nextInt();
		
		ArrayList<Integer> survey = 
			new ArrayList<Integer>(Collections.nCopies(500, 0));

		//assert(survey.size() > 300);

		for(int i = 0; i < a; i++)
		{
			for(int j = 0; j < p; j++)
			{
				if(i == 0)
				{
					
					survey.set(j, sc.nextInt());
				}
				else
				{
					int tmp = sc.nextInt();
					if(tmp != survey.get(j)) 
					{
						survey.set(j, -1);
					}
				}
			}
		}

		int c = sc.nextInt();
		//err.println("c: " + c);

		int cont = 0;

		for(int i = 0; i < c; i++)
		{
			boolean posible = true;
			for(int j = 0; j < p; j++)
			{
				int feature = sc.nextInt();
				if(survey.get(j) != feature && survey.get(j) != -1) {
					//err.print(i);
					//err.print(' ');
					//err.println(j);
					posible = false;					
				}
			}
			if(posible)
				cont++;
		}

		out.println(cont);
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
