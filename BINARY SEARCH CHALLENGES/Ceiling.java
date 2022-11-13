package SEARCHING.BinarySearchProblems;

import java.util.*;
import java.util.Scanner;
import java.util.Arrays;

// find greatest element in array smaller to target element 

public class Ceiling {
    public static void main(String[] args){
        int[] arr = {2,3,5,9,10,14,16,18};       
        int l = 0, r = arr.length-1;
        int target = 19; 
        
        if(arr[arr.length-1]<target)
            System.out.println("-1");
        
        else{
            while(l<=r){
                int mid = l + (r-l)/2;
                if(arr[mid]>=target) r = mid-1; 
                else l = mid+1;
            }
            System.out.println(arr[l]);
        }

    }
}
