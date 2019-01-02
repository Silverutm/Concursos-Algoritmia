import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);
        
        int n,a,b,faltan,cambia,x;
        int ar1[]= new int[1001];
        int ar2[]= new int[1001];
        boolean capt[] = new boolean[1001];
        boolean nointer[] = new boolean[1001];
        while(sca.hasNext())
        {
            faltan = 0;
            cambia = 0;
            n = sca.nextInt();
            for(int i=0;i<1001;i++)
            {
                capt[i] = false;
                nointer[i] = false;
            }
            a = sca.nextInt();
            for(int i=0;i<a;i++)
            {
                x = sca.nextInt();
                capt[x] = true;
            }
            b = sca.nextInt();
            for(int i=0;i<b;i++)
            {
                x = sca.nextInt();
                nointer[x] = true;
            }
            for(int i=1;i<=n;i++)
            {
                if(capt[i] == false && nointer[i] == false)
                {
                    ar1[faltan++] = i;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(capt[i] == true && nointer[i] == true)
                {
                    ar2[cambia++] = i;
                }
            }
            System.out.print(faltan);
            for(int i=0; i<faltan; i++)
            {
                System.out.print(" "+ar1[i]);
            }
            System.out.print("\n"+cambia);
            for(int i=0; i<cambia; i++)
            {
                System.out.print(" "+ar2[i]);
            }
            System.out.println();

        }
    }
}
