// #include<bits/stdc++.h>
// using namespace std;

// void swap(int ar[], int i, int j){
//     int temp = ar[i];
//     ar[i] = ar[j];
//     ar[j] = temp ; 
// }
// // int partition1(int a[], int l, int r){
// //     int pivot = a[r]; // considering last element as pivot
// //     int i = l-1; /* i pointer starts from -1 indexed */
// //     for(int j=l;j<r;j++)
// //     {
// //         if(a[j] < pivot)
// //         {
// //             i++; 
// //             swap(a,i,j);
// //         }
// //     }
// //     swap(a, i + 1, r); /* for pivot */
// //     return i+1; 
// // }
// int partition2(int a[], int s, int e){
//     int pivot = a[s], lessCount = 0; 
//     for(int i=s;i<=e;i++){
//         if(a[i]<pivot) lessCount++; 
//     }

//     int pivotidx = s + lessCount; 
//     swap(a,pivotidx,s); // bcz a[s] is previous pivot

//     int i=s, j=e;
//     while(i<pivotidx and j>pivotidx){
//         while(pivot>a[i]) i++; 
//         while(pivot<a[j]) j--;
//         if(i<pivotidx and j>pivotidx)
//             swap(a,i++,j--); 
//     }

//     return pivotidx;
// }
// void quicksort(int arr[], int l, int r){
//     if(l<r){
//         // int pi = partition1(arr, l, r);
//         int pi = partition2(arr, l, r);
//         quicksort( arr, l, pi-1 );
//         quicksort( arr, pi+1, r );
//     }
// }
// int main(){
//     int a[8] = { 6, 3, 9, 5, 2, 8, 7, 4};
//     quicksort(a,0,7);
//     for(int i=0;i<8;i++)
//         cout<<a[i]<<" ";
//     cout<<endl; 
//     return 0;
// }
