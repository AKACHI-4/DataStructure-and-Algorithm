package SEARCHING.BinarySearchProblems;

// find smallest element in array greater to target element 

import java.util.*;
import java.util.Scanner;
import java.util.Arrays;

public class floorOP {
    public static void main(String[] args){
        int[] arr = {2,3,7,9,11,14,17};
        int l=0, r=arr.length-1;
        int target = 8, ans;

        if(target<arr[l])
            ans = -1;
        else{
            while(l<=r){
                int mid = l + (r-l)/2;
                if(arr[mid]>=target) r = mid-1; 
                else l = mid+1;
            }
            ans = arr[r];
        }

        System.out.println(ans);     
    }
}
