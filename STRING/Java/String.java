import java.util.*; 
import java.util.Scanner;
import java.util.Arrays;

public class String {
    public static void main(String[] args){
        // String name = "Kunal kushwaha"; 
        // System.out.println(name); // Kunal kushwaha
        
        // String a = "Adarsh"; 
        // System.out.println(a); // Adarsh
        // a = "Hare Krishna"; 
        // System.out.println(a); // Hare Krishna

        // Here I didn't changed 'Adarsh' object actually I created a new object 'Hare Krishna' and assigned 'a' with it.
        // and now 'Adarsh' object is collected as garbage in memory

        // For security reasons strings are immutable

        // Comparison of two Strings

        // String a = "Krishna"; 
        // String b = "Krishna"; 

        // == (comparator) method
        // if ref variable are pointing to differnt objects even they have same value it return false
        // if ref variable are pointing to same object so it retrun true

        // how to create two different object having same value - using new keyword

        String a = new String("Krishna");
        String b = new String("Krishna");
        // creating these value outside pool but in heap 

        // When we only need to check value, use .equals() method
        System.out.println(a==b); // false
        System.out.println(a.equals(b)); // true
        System.out.println(a.charAt(2)); // i
    
        // simple a to z print every 1 pass from 1 to 26 we observe that every time a new object created in pool which increase size by 1+2+3+...+N - N^2 ... absolutely performance get reduced. 
        // Wanna overcome this Use StringBuilder
        
        // StringBuilder made only one object and changes are made into that object only. 

    }
}
