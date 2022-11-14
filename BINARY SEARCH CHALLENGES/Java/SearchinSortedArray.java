package SEARCHING.BinarySearchProblems;

import java.util.*;

public class SearchinSortedArray {
    public static void main(String[] args){
        int[] arr ={4,5,6,7,0,1,2}; 
        int target = 6; 
        System.out.println(search(arr,target));       
    }
    public static int search(int[] nums, int target) {
        int idx = pivotidx(nums), ans;  
        if(target>=nums[0] && target<=nums[idx])
            ans = binsearch(nums,0,idx,target); 
        else ans = binsearch(nums,idx+1,nums.length-1,target);
        return ans; 
    }
    public static int pivotidx(int[] arr){
        int l = 0, r = arr.length-1;
        while(l<=r){
            int mid = l + (r-l)/2; 
            
            if(mid<r && arr[mid]>arr[mid+1]) return mid; 
            if(mid>l && arr[mid]<arr[mid-1]) return mid-1;
            
            if(arr[l]>=arr[mid]) r = mid-1; 
            else l = mid+1; 
        }
        return -1; 
    }
    public static int binsearch(int[] arr, int l, int r, int key){
        while(l<=r){
            int mid = l + (r-l)/2; 
            
            if(arr[mid]==key) return mid;
            
            if(arr[mid]>key) r = mid-1; 
            else l = mid+1; 
        }
        return -1;
    }
}
