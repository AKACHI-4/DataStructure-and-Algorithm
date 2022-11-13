import java.util.Scanner;
import java.util.*;

public class PrimeArmstrong {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        
        System.out.print("Input a number : ");
        int a = in.nextInt(); 

        // if(prime(a))
        //     System.out.println(a + " is a prime number");
        // else
        //     System.out.println(a + " is not a prime number");

        if(armstrong(a))
            System.out.println(a + " is an armstrong number");

        for(int i=100;i<=999;i++){
            if(armstrong(i))
                System.out.print(i + " ");
        }

    }

    static boolean armstrong(int n){
        int fake = n;
        int sum = 0; 
        while(fake!=0){
            int rem = fake%10;
            sum = sum + rem*rem*rem;
            fake = fake/10;  
        }
        if(sum==n)
            return true;
        else return false;

    }

}
