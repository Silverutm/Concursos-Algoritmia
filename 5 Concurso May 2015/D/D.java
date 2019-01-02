import java.util.*;

class Dmain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();

		while (tt-- > 0) 
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			System.out.println(n == 1 ? 1 : (n*m - n)/2 + n);
		}
	}
}