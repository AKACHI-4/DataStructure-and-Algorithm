import java.util.*; 

public class BasicProblems{
    public static void main(String[] args){ 
        // Sum of first N numbers 
        
        // System.out.print("Enter a number : "); 
        // Scanner in = new Scanner(System.in); 
        // int N = in.nextInt(); 

        // // recur_1(N,0); // Parameterised 
        
        // // 2. Functional Recursion 
        // int ans = recur_2(N);
        // System.out.println("Sum of 1 to " + N + " numbers is : " + ans);
        
        
        // Print 1 to N in increasing and Decreasing order using backtracking

        System.out.print("Enter a number : "); 
        Scanner in = new Scanner(System.in); 
        int num = in.nextInt(); 

        System.out.print("Increasing order is : ");
        Inc1_N(num); 
        System.out.println(); 
        System.out.print("Decreasing order is : ");
        DecN_1(1,num);

    }
    // 1. Parameterised 
    // static void recur_1(int i,int sum){
    //     if(i<1){ 
    //         System.out.println("Sum is : " + sum); 
    //         return ; 
    //     }
    //     recur_1(i-1, sum+i);
    // }
    // 2. Functional Recursion
    // static int recur_2(int i){
    //     if(i<1)
    //         return 0; 
    //     return i + recur_2(i-1);
    // }
    static void Inc1_N(int i){
        if(i<1){
            return; 
        }
        Inc1_N(i-1);
        System.out.print(i+" "); 
    }
    static void DecN_1(int i, int N){
        if(i>N){
            return; 
        }
        DecN_1(i+1,N); 
        System.out.print(i+" ");
    }
}