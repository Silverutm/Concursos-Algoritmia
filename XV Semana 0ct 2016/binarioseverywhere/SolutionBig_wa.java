import java.io.*;
import java.util.*;
import java.math.*;



public class SolutionBig{
	public static Scanner sc = new Scanner(System.in);
	public static boolean debuguea = false;

	public static void deb(BitSet bs, int n) {
		if(debuguea == false)
			return;
		for (int i=0; i < n; i++) {
			if(i != 0)
				System.err.print(" ");

			System.err.print(bs.get(i)?1:0);
		}
		System.err.println();
	}

	public static void solve() {
		int a = sc.nextInt();
		int p = sc.nextInt();

		if(debuguea)
		{
			System.err.print(a);
			System.err.print(' ');
			System.err.println(p);
		}


		BitSet carac = new BitSet(p);
		carac.set(0, p);

		boolean dissagrements = false;

		BitSet obli = new BitSet(p);
		obli.set(0, p);
		for(int i = 0; i < a; i++) {
			for (int j = 0; j < p; j++) {
				boolean b = (sc.nextInt()==1)? true : false;
				if(i > 0 && b != carac.get(j))
				{
					obli.set(j, false);
					dissagrements = true;
				}

				carac.set(j, b && carac.get(j));

			}
		}

		int c = sc.nextInt();
		BitSet cel = new BitSet(p);
		int cont = 0;

		//System.err.println("la wea");
		//deb(carac, p);
		

		for(int i = 0; i < c; i++) {
			for(int j = 0; j < p; j++) {
				cel.set(j, ((sc.nextInt()==1)? true : false));
			}
			if (debuguea) {
				System.err.println(i+1);
			}
			deb(carac, p);
			deb(cel, p);
			
			BitSet tmp = (BitSet)cel.clone();

			assert(tmp.equals(cel));

			if(dissagrements)
				tmp.and(carac);

			deb(tmp, p);
			if(debuguea)
				System.err.println();


			if(tmp.equals(carac))
			{
				if(debuguea)
					System.err.println("^^ +1");
				cont++;
			}
		}
		System.out.println(cont);

		if(debuguea)
			System.err.println(cont);
	}

	public static void main(String[] args) {
		
		int N = sc.nextInt();
		
		for(int i = 0; i < N; i++)
		{
			if(i == 62)
				debuguea = true;
			solve();
			debuguea = false;

		}
	}
}
