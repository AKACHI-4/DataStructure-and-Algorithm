package SEARCHING;

import java.util.*;
import java.util.Scanner;
import java.util.Arrays;

public class LinearSearch {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in); 
        
        // System.out.print("Enter size of the Array : ");
        // int n = in.nextInt(); 
        // int[] arr = new int[n]; 
        // for(int i=0;i<n;i++)
        //     arr[i] = in.nextInt();
        
        // System.out.print("Enter the target : ");
        // int tar = in.nextInt(); 

        // int[] ans = linearsearch1D(arr,0,n-1,tar); 

        // if(ans != null)
        //     System.out.println(tar + " = " + ans[0] + " found at index " + ans[1]);
        // else 
        //     System.out.println(tar + " not found");

        int[][] arr2 = {
            {12,34,67},
            {13,10,14,19},
            {45,23}
        };

        System.out.print("Enter the target : ");
        int key = in.nextInt(); 

        int[] rc = linearsearch2D(arr2,key); 

        if(rc!=null)
            System.out.println(key + " find at index " + Arrays.toString(rc));
        else
            System.out.println(key + " not exist!!");

    }
    // static int[] linearsearch1D(int[] arr, int st, int en, int key){
    //     if(arr.length==0)
    //         return null;

    //     for(int i=st;i<en;i++){
    //         if(arr[i]==key)
    //             return new int[]{arr[i],i};
    //     }
    //     return null;
    // }

    static int[] linearsearch2D(int[][] arr, int key){
        if(arr.length==0)
            return null;

        for(int r=0;r<arr.length;r++){
            for(int c=0;c<arr[r].length;c++){
                if(arr[r][c]==key)
                    return new int[]{r,c};
            }
        }

        return null;
    }

}
