import java.util.*;
import java.math.*;

class Fmain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();

		while (tt-- > 0)
		{
			int n = sc.nextInt();

			int r = (int)Math.sqrt(n);
			System.out.printf("%s\n", r*r == n ? "son unos genios" : "les hace falta estudiar");
		}
	}
}