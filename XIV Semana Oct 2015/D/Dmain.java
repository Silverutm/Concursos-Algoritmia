import java.util.*;

class Dmain{//Ejemplo del nombre de la clase
//para el problema B

    public static void main(String []args)
    {
        /*Scanner sc = new Scanner(System.in);
        
        int casos,a,b;
        
        casos = sc.nextInt();
        
        while(casos-- > 0)
        {
       	    a = sc.nextInt();
            b = sc.nextInt();
            
            System.out.println(a+b);
        }*/
        
        Scanner sc = new Scanner(System.in);
        int t, m, s,n;
        String a;
        a = "";
        //cin>>t;
        t=sc.nextInt();
        while (t-- > 0)
        {
            //cin>>m;
            m=sc.nextInt();
            a=sc.nextLine();
            s=n=0;
            while (m-- > 0)
            {
                //cin>>a;
                a=sc.nextLine();                
                if (a.equals("si")) ++s;
                else ++n;                
            }
            if (n*5>=(n+s)) System.out.println("friendzone\n");
            else System.out.println(":)\n");
        }
                        
    }
}