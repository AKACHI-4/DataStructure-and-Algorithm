package SEARCHING;

import java.util.*;
import java.util.Scanner;
import java.util.Arrays;

public class BinarySearch {
    public static void main(String[] args){
        // Scanner in = new Scanner(System.in); 

        // int[] arr = {-78,-56,-23,-12,-6,15,25,33,45,61,78};
        int[] arr = {45,34,23,12,9,-6,-12,-26,-45};
        int target = -12; 
        System.out.println(OrderAgnosticBinSearch(arr,target));
    }

    static int OrderAgnosticBinSearch(int[] arr, int key){
        int l = 0; 
        int r = arr.length-1; 

        // check whether array is in asending oreder or decending order
        boolean isAsc; 
        if(arr[l]>arr[r]) isAsc = false;
        else isAsc = true;

        while(l<r){
            int mid = l + (r-l)/2;
            if(arr[mid]==key)
                return mid;
            
            // if array is in ascending order
            if(isAsc){
                if(arr[mid]>key)
                r = mid-1;
                else l = mid+1;
            }
            // if array is in descending order
            else{
                if(arr[mid]<key)
                    r = mid-1;
                else l = mid+1;
            }
        }

        return -1;
    }
}
