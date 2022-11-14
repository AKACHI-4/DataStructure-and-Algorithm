#include<bits/stdc++.h>
using namespace std;

// considering maxHeap
class Heap{ 
    int arr[100]; 
    int size; 
    public:
        Heap(){
            size = 0; 
            arr[0] = -1;
        }

        void insert(int val){
            arr[++size] = val; 
            int index = size; 

            while(index>1){
                int parent = index/2; 

                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]); 
                    index = parent; 
                }else{ 
                    return ; 
                }
            }

        }

        void print(){ 
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" "; 
            }
        }
};

signed main(){
    Heap h1; 
    h1.insert(60);
    h1.insert(30);
    h1.insert(50);
    h1.insert(20);
    h1.insert(40);
    h1.insert(70);
    h1.insert(55);

    h1.print();

    return 0;
}