import java.util.Scanner; 
import java.util.Arrays;
import java.io.*;

public class Array {
    // 1. Array of primitives 

    // Array Syntax 
    // datatype[] variable_name = new datatype[size];
    // defined variable name actually is a reference variable 

    // datatype[] var_name; declaration : Array is getting defined in the stack -> In Compile time 
    // var_name = new datatype[size]; Intiallization : Actually here object created in the heap memory -> In Run time -> so Dynamic memory allocation
    // new is used to create an object dynammically in heap memory. 
    // by default value is zero in array 

    // null -> special litheral, which can be assign to any reference type(None in python) and you can typecast null to any type except primitive datatype, by default value what reference variable point to


    // In java, there are no concept of pointers so continuity of array totally depends upon JVM whether this is going to be continuos or not 
    // Why? 
    // 1. array objects are created into heap 
    // 2. (In JLS(java language specification), it is mentioned that heap objects are not continuous)
    // 3. heap is the runtime data area, from which the memory for all the classes or instances or arrays are created
    // Conclusion: In JAVA, array objects may not be continuous and depends upon JVM

    // Out of bound error - if access out of bound value 
    // tostring() - Used to convert into string

    // for-each loop 
    // syntax 
    // for (datatype var_name : Array_name) { }


    // 2. Array of objects 
    // Such as Array of String 

    // 3. 2D Array or Matrix (MultiDimensional Array)
    // In terms of for-each loop, for 2D array
    // for(datatype[] var_name : Array_name) { }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in); 

        // int[] arr = new int[5]; 

        // for(int i=0;i<5;i++){
        //     arr[i] = in.nextInt(); 
        // }

        // for(int i=0;i<5;i++)
        //     System.out.print(arr[i]+" ");
        // System.out.println();

        // System.out.println(Arrays.toString(arr));

        // String[] bigstr = new String[3]; 

        // for(int i=0;i<3;i++)
        //     bigstr[i] = in.next(); 

        // for(String str : bigstr)
        //     System.out.print(str+" ");
        // System.out.println();

        // System.out.println(Arrays.toString(bigstr));

        
        // int[][] arr = new int[3][3]; 
        // System.out.println(arr.length);

        // for(int i=0;i<arr.length;i++){
        //     for(int j=0;j<arr[i].length;j++)
        //         arr[i][j] = in.nextInt();
        // }
        
        // for(int i=0;i<arr.length;i++){
        //     for(int j=0;j<arr[i].length;j++)
        //         System.out.print(arr[i][j]+" ");
        //     System.out.println();
        // }
        
        // for(int i=0;i<arr.length;i++){
        //     System.out.println(Arrays.toString(arr[i]));
        // }

        // for(int[] arr1 : arr)
        //     System.out.println(Arrays.toString(arr1));

        int[][] arr2 = {
            {1,2,3,4},
            {5,6,7},
            {8,9,12,13}
        };

        for(int i=0;i<arr2.length;i++){
            for(int j=0;j<arr2[i].length;j++)
                System.out.print(arr2[i][j]+" ");
            System.out.println();
        }

        for(int[] arr1 : arr2)
            System.out.println(Arrays.toString(arr1));
        
    }

}
