import java.util.*; 

public class Subsequence{
    private static void Display(int idx, ArrayList<Integer> ans, int[] arr, int sz){
        if(idx>=sz){
            for(int i : ans){
                System.out.print(i+" ");
            }
            System.out.println(); 
            return ; 
        }
        ans.add(arr[idx]); 
        Display(idx+1, ans, arr, sz);
        ans.remove(ans.size()-1); 
        Display(idx+1, ans, arr, sz);
    }
    public static void main(String[] args){
        int[] arr = {3,1,2}; 
        int n = arr.length; 
        ArrayList<Integer> ans = new ArrayList<>(); 
        Display(0,ans,arr,n); 
    }
}