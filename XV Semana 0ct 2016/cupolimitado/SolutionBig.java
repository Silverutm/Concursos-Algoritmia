import java.io.*;
import java.util.*;
import java.math.*; 
 
public class SolutionBig{
	public static MyScanner sc = new MyScanner();
	public static PrintWriter out;
	public static PrintWriter err;
	/*************************************************************/

	public static class Conferecia implements Comparable<Conferecia> {
		public long ini;
		public long fin;

		public Conferecia(long ini, long fin) {
			this.ini = ini;
			this.fin = fin;
		}

		@Override
		public int compareTo(Conferecia o) {
			if(fin < o.fin)
				return -1;
			else if(fin > o.fin)
				return 1;
			else
			{
				if(ini < o.ini)
					return -1;
				else if(ini > o.ini)
					return 1;
				else
					return 0;
			}
		}
	}


	public static ArrayList<Conferecia> conferencias = 
		new ArrayList<Conferecia>();

	static void solve() {
		int n   = sc.nextInt();
		conferencias.clear();

		for (int i = 0; i < n; i++) {
			Conferecia c = new Conferecia(sc.nextLong(), sc.nextLong());
			conferencias.add(c);
		}
		Collections.sort(conferencias);

		int cont = 0;
		long prevFin = 0;
		for (int i = 0; i < n; i++) {
			long ini = conferencias.get(i).ini;
			long fin = conferencias.get(i).fin;

			// err.println(
			//  	"i: " + conferencias.get(i).ini + " " +
			// 	"f: " + conferencias.get(i).fin
			// );

			if(ini >= prevFin) {
				cont++;
				prevFin = fin;
			}
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
