import java.util.*;

class Hmain{//Ejemplo del nombre de la clase
//para el problema B

    static int gcd(int a, int b)
    { return b!=0 ? gcd(b, a % b) : a; }
    
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        
       /* int casos,a,b;
        
        casos = sc.nextInt();
        
        while(casos-- > 0)
        {
       	    a = sc.nextInt();
            b = sc.nextInt();
            
            System.out.println(a+b);
        }*/
        
        int tt;
        tt=sc.nextInt();
 
        while (tt-- > 0)
        {
            int a, b;
            //scanf("%d %d", &a, &b);
            a=sc.nextInt();
            b=sc.nextInt();
            if ( gcd(a,b)!=1 )
                System.out.println("no\n");
            else System.out.println("si\n");
            
        }
 
     


        
    }
}