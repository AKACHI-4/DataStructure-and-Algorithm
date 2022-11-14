import java.util.*; 
import java.util.Scanner;
import java.util.Arrays;

public class CyclicSort {
    public static void main(String[] args){
        int[] arr = {3,5,2,1,4}; 
        cyclicsort(arr); 
        print(arr);         
    }   

    static void cyclicsort(int[] arr){
        // for(int i=0;i<arr.length;i++){ 
        //     if(arr[i]-1!=i){ 
        //         while(arr[i]-1!=i){
        //             swap(arr,i,arr[i]-1);
        //         }
        //     }
        // }

        // or 
        
        // int i = 0; 
        // while(i<arr.length){ 
        //     int correctidx = arr[i]-1; 
        //     if(correctidx!=i){
        //         swap(arr,i,correctidx);
        //     }else{
        //         i++; 
        //     }
        // }

        // or

        // if duplicates
        int i = 0; 
        while(i<arr.length){
            int correct = arr[i]-1; 
            if(arr[correct]!=arr[i]) swap(arr,i,correct);
            else i++; 
        }
    }

    static void print(int[] arr){
        for(int i=0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
        System.out.println('\n');
    }

    static void swap(int[] arr, int i, int j){
        int temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp; 
    }

}
