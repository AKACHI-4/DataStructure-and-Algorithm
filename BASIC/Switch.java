import java.util.Scanner;

public class Switch {
    public static void main(String[] args){
        // Manual calculator 
        Scanner in = new Scanner(System.in); 
        /*
            switch(expression){
                case 1 : // statement
                    break; 
                case 2 : // statement
                    break; 
                case 3 : // statement
                    break; 
                case 4 : // statement
                    break; 
                case 5 : // statement
                    break; 
                case 6 : // statement
                    break;
                default : // statement 
            }
        */

    // System.out.print("Enter no. of times you want to perform operation : ");
    //     int op = in.nextInt(); 
    //     while(op!=0){
    //         System.out.print("which operation you want to perform : ");
    //         char ch = in.next().charAt(0); 
    //         int ans;  
    //         switch(ch){
    //             case '+' -> {
    //                 System.out.print("Enter two numbers : ");
    //                 int a = in.nextInt(), b = in.nextInt();
    //                 System.out.println(a + " + " + b + " = " + (int)(a+b));
    //             }
    //             case '-' -> {
    //                 System.out.print("Enter two numbers : ");
    //                 int a = in.nextInt(), b = in.nextInt();
    //                 System.out.println(a + " - " + b + " = " + (int)(a-b));
    //             }
    //             case '*' -> {
    //                 System.out.print("Enter two numbers : ");
    //                 int a = in.nextInt(), b = in.nextInt();
    //                 System.out.println(a + " * " + b + " = " + (int)(a*b));
    //             }
    //             case '/' -> {
    //                 System.out.print("Enter two numbers : ");
    //                 int a = in.nextInt(), b = in.nextInt();
    //                 System.out.println(a + " / " + b + " = " + (int)(a/b));
    //             }
    //             case '%' -> {
    //                 System.out.print("Enter two numbers : ");
    //                 int a = in.nextInt(), b = in.nextInt();
    //                 System.out.println(a + " % " + b + " = " + (int)(a%b));
    //             }
    //             default -> {
    //                 System.out.println("plz, Enter a valid operator!!"); 
    //                 op++; 
    //             }
    //         }
    //         op--; 
    //     }
    // }

        int day = in.nextInt(); 
        switch(day){
            case 1, 2, 3, 4, 5 -> {
                System.out.println("Weekday");
                break;
            }
            case 6, 7 -> {
                System.out.println("Weekend");
                break;
            }
            default -> System.out.print("Wrong Day no. !!");
        }

    }
}
