import java.util.Random;

class Genera
{
	public static void main(String[] args)
	{
		Random r = new Random();

		int aux, n, k;
		float bx, by, px, py;

		System.out.println("500");

		for(int i = 0; i < 500; i++)
		{
		 	bx = r.nextFloat() * r.nextInt(500);
			by = r.nextFloat() * r.nextInt(500);

			if(r.nextInt(1) == 1)
				bx = bx*-1;

			if(r.nextInt(1) == 1)
				by = by*-1;

			System.out.println(bx + " " + by);

			n = r.nextInt(200) + 1;

			if(n == 1)
				k = 1;
			else
				k = r.nextInt(n-1) + 1;



			System.out.println(n + " " + k);

			for(int j = 0; j < n; j++)
			{
				px = r.nextFloat() * r.nextInt(500);
				py = r.nextFloat() * r.nextInt(500);

				if(r.nextInt(1) == 1)
					px = px*-1;

				if(r.nextInt(1) == 1)
					py = py*-1;

				System.out.println(px + " " + py);
			}

			System.out.println("*");

		}
	}
}