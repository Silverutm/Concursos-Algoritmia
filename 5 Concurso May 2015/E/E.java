import java.util.*;

class Emain
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();


		while (tt-- > 0)
		{
			int k = sc.nextInt();
			sc.nextLine();
			String line = sc.nextLine();

			for(int i = 0; i < line.length(); i++)
				System.out.print((char)(line.charAt(i) ^ k));
			System.out.println();
		}
	}
}