import java.util.Scanner;

class A
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		while (T-- > 0)
		{
			double Ax = sc.nextDouble(), Ay = sc.nextDouble();
			int Q = sc.nextInt();

			while (Q-- > 0)
			{
				double Cx = sc.nextDouble(), Cy = sc.nextDouble();
				if ((Ax - Cx)*(Ax - Cx) + (Ay - Cy)*(Ay - Cy) <= 500*500)
					System.out.println("FULL COMBO");
				else
					System.out.println("OUTPLAYED");
			}
		}
	}
};