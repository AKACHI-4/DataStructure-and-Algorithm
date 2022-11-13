import java.util.*;
import java.util.Scanner;
import java.util.ArrayList;

public class ArrayQuestion {
    public static void main(String[] args){
        int[] arr = {94,21,32,14,56,61};

        for(int i=0;i<arr.length;i+=2){
            swap(arr,i,i+1);
        }

        System.out.println(Arrays.toString(arr));

        System.out.println(max(arr,0,5));

        reverse(arr,0,arr.length-1); 

        System.out.println(Arrays.toString(arr));
    }

    public static void reverse(int[] arr, int i, int j){
        while(i<j){
            swap(arr,i,j); 
            i++; 
            j--;
        }
    }
    
    public static void swap(int[] arr, int a, int b){
        int temp = arr[a];
        arr[a] = arr[b]; 
        arr[b] = temp; 
    }

    public static int max(int[] arr, int st, int en){
        Integer Max = Integer.MIN_VALUE; 
        
        for(int i=st;i<=en;i++){
            Max = Math.max(Max, arr[i]);    
        }

        return Max; 
    }

}
