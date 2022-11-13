import java.util.*;
import java.util.Scanner;
import java.util.ArrayList;

public class dynamicarray {
    // 1. ARRAYLIST (Dynamic Arrays)
    // when size of array is not main concern 
    // ArrayList is the part of collection framework
    // initial capacity of ArrayList : 10

    // STL of java -> collection framework

    // Syntax
    // ArrayList<wrapper class> name = new ArrayList<wrapper class>();
    // wrapper class is modified type of primitives in which can use numerous function as well 
    // not necessary to include wrapper class in 2nd encounter
    // slower than standard array 
    // list[index] will not work here

    // size is fixed internally 
    // on size conflicts new double size arraylist created old elements copied there new will be added and old arraylist get deleted
    // Time complexity : O(1)

    // Mutli dimension ArrayList
    // ArrayList<ArrayList<wrapper class>> = new ArrayList<>();

    public static void main(String[] args){
        Scanner in = new Scanner(System.in); 

        // ArrayList<Integer> newList = new ArrayList<>(); 

        // for(int i=1;i<=10;i++)
        //     newList.add(i); 

        // System.out.println(newList.contains(15));

        // System.out.println(newList);
        // newList.set(5,90);
        // System.out.println(newList);
        // newList.remove(2);
        // System.out.println(newList);
        
        // for(int i=0;i<5;i++)
        //     newList.add(in.nextInt());

        // System.out.println(newList);
        
        // ArrayList<ArrayList<Integer>> List2 = new ArrayList<>(); 

        // for(int i=0;i<4;i++)
        //     List2.add(new ArrayList<>());

        // for(int i=0;i<4;i++){
        //     for(int j=0;j<4;j++)
        //         List2.get(i).add(in.nextInt());
        // }

        // System.out.println(List2);

    }
}
