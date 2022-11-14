#include<bits/stdc++.h>
using namespace std;

#define vb vector<bool>
#define mii map<int,int> 
#define rep(i,a,b) for(int i=a;i<b;i++)

signed main(){
    int MinSteps = 0;

    int ladders; cin>>ladders; 
    mii lad; 
    rep(i,0,ladders){
        int x, y; cin>>x>>y; 
        lad[x] = y;
    }
    int snake; cin>>snake; 
    mii snk; 
    rep(i,0,snake){
        int x, y; cin>>x>>y; 
        snk[x] = y;
    }

    vb visited(101,false); // very important As it reduces time complexity to O(n) from exponential power because after using this we no need to check that should we visit particular square or not
    
    queue<int> q; 
    q.push(1);
    visited[1] = true;

    bool win = false; 

    int num = 0;
    while(!q.empty() and !win){
        int size = q.size(); // necessary because every iteration there are 6 elements which get pushed in queue
        // and so we can get result for all six element once don't need to check seprately 
        cout<<size<<endl;
        

        while(size--){
            int x = q.front(); 
            q.pop(); 
            for(int dice=1;dice<=6;dice++){
                num++; 
                if(x+dice==100) win = true; 
                if(x+dice<=100 and lad[x+dice] and !visited[lad[x+dice]]){
                    visited[lad[x+dice]] = true;
                    if(lad[x+dice]==100) win = true; 
                    q.push(lad[x+dice]);
                }
                else if(x+dice<=100 and snk[x+dice] and !visited[snk[x+dice]]){
                    visited[snk[x+dice]] = true; 
                    if(snk[x+dice]==100) win = true; // mjk h kya 
                    q.push(snk[x+dice]);
                }
                else if(x+dice<=100 and !lad[x+dice] and !snk[x+dice] and !visited[x+dice]){
                    visited[x+dice] = true; 
                    q.push(x+dice); 
                }
            }
        }
        MinSteps++; 
    } // Time Complexity : O(n)

    cout<<"Minimum steps to win game: "<<MinSteps<<endl;

    return 0;
}