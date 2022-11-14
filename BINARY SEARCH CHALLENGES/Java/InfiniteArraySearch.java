package SEARCHING.BinarySearchProblems;

import java.util.*;

public class InfiniteArraySearch {
    public static void main(String[] args){
        int[] arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    
        int st = 0; 
        int en = 1;

        int target = 17;

        while(arr[en]<target){
            int newst = en+1;
            // en = en + boxsize(en-st+1)
            en += en-st+1;
            st = newst; 
        }

        System.out.println(binarysearch(arr,st,en,target));
    }

    public static int binarysearch(int[] arr, int l, int r, int target){

        while(l<=r){
            int mid = l + (r-l)/2; 
            if(arr[mid]>target)
                r = mid-1;
            else l = mid+1;
        }

        return r; 
    }
}
