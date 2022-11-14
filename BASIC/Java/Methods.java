import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

public class Methods {
    static int val = 5; 
    public static void main(String[] args){
        Scanner in = new Scanner(System.in); 
        
        // sum(); 

        System.out.print("Enter two values: ");
        int a = in.nextInt(); 
        int b = in.nextInt(); 
        // int multi = multiply(a,b); 
        // System.out.println("Multiply is : " + multi);

        // String str = greet(); 
        // System.out.println("string is: " + str);

        // System.out.print("Enter two values: ");
        // int a = in.nextInt(); 
        // int b = in.nextInt(); 

        // passbyValue(a,b); 

        // int[] arr = {1,2,34,23,56,65,3};

        // System.out.println("value at 3rd index: " + arr[3]);

        // change(arr); 
        // here reference name is passed as value 

        // System.out.println("value at 3rd index: " + arr[3]);

        // System.out.println(Arrays.toString(arr));

        // System.out.print("After pass by value: " + a + " " + b );

        // String name = "Hey Adarsh"; 

        // call(name); 
        // also reference will be paas as value so changes will reflect

        // System.out.print("String after call: " + name);

        fun(a,b);
        System.out.print("After pass by value: " + a + " " + b );

        // System.out.println("val in main: " + val);

    }    

    static void arr(int ...val){
        System.out.println(val.toString());
    }
    
    static void fun(int num1, int num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // static void call(String str){
    //     str = "Hello Adarsh"; // new object created 
    // }

    // static void change(int[] array){
    //     array[3] = 90; // here array is actually reference to array so in changing here in array will be reflect in arr 
    // }

    // static void passbyValue(int a, int b){
    //     int temp = a; 
    //     a = b; 
    //     b = temp; 

    //     System.out.println("After pass by value: " + a + " " + b );
    // }

    // static void sum(){
    //     Scanner in = new Scanner(System.in); 
    //     System.out.print("Enter two values: ");
    //     int a = in.nextInt(); 
    //     int b = in.nextInt(); 
    //     int sum = a + b; 
    //     System.out.println("Sum is : " + sum);
    // }

    // static int multiply(int a, int b){
    //     return a * b ; 
    // }

    // static String greet(){
    //     return "Happy Coding!!";
    // }

}
