/* bonus tip is attached in last lines */

// 1. find the no. of connected components in a graph and its size.

// UNDIRECTED GRAPH

// #include<bits/stdc++.h>
// using namespace std;

// #define vi vector<int> 
// #define vvi vector<vector<int>> 
// #define vb vector<bool> 
// #define rep(i,a,b) for(int i=a;i<b;i++)

// vb visited; 
// int n, m; // n->edges m->nodes
// vvi adjL;
// vi components;  

// int get_components(int idx){ 
//     if(visited[idx])
//         return 0; 
//     visited[idx] = true;
//     int ans = 1; // after getting idx visited we have one node in that component so size of componet is 1
//     for(auto i : adjL[idx]){
//         /* only visit unvisited nodes don't need to visit already visited nodes */
//         if(!visited[i]){
//             ans += get_components(i);
//             visited[i] = true;
//         }
//     }
        
//     return ans;
// }
// signed main(){
//     cin>>n>>m; 
//     adjL = vvi(m);
//     visited = vb(m,0);
//     rep(i,0,n){
//         int x, y; cin>>x>>y; 
//         adjL[x].push_back(y);
//         adjL[y].push_back(x);
//     }

//     for(int i=0;i<m;i++){
//         if(!visited[i])
//             components.push_back(get_components(i));
//     }

//     long long ways = 0; 
//     for(auto i : components){
//         cout<<i<<" ";
//         ways += i*(m-i);
//     } 

//     cout<<endl;
//     cout<<"No. of Ways to do so : "<<ways/2<<endl;

//     return 0;
// }


// 2. There are N friends numbered from 0 to N-1. you have to choose 2 person such that they are not related to each other. you are given information in the form of M pairs (X,Y) i.e. there is an link between friend X and Y. Find out the number of ways in which 2 persons from different groups can be chossen. 

// #include<bits/stdc++.h>
// using namespace std;

// #define vi vector<int> 
// #define vvi vector<vi> 
// #define vb vector<bool> 
// #define rep(i,a,b) for(int i=a;i<b;i++)

// int get_relation(int idx, vb &check_relation, vi adjL[]){
//     if(check_relation[idx]) 
//         return 0; 
//     check_relation[idx] = true;
//     int connection = 1; 
//     for(auto i : adjL[idx]){
//         if(!check_relation[i]){
//             connection += get_relation(i,check_relation,adjL);
//             check_relation[i] = true;
//         }
//     }
//     return connection; 
// }
// signed main(){
//     int N, M; cin>>N>>M; 
//     // N -> no. of friends M -> pairs (*means no. of  connection between those friends in pair)
//     vi adjL[N];
//     vb check_relation(N,false);
//     vi relative_components; 
//     rep(i,0,M){
//         int x, y; cin>>x>>y; 
//         adjL[x].push_back(y);
//         adjL[y].push_back(x);
//     }
//     rep(i,0,N){
//         if(!check_relation[i])
//             relative_components.push_back(get_relation(i,check_relation,adjL));
//     }
//     long long Ways = 0; 
//     for(auto i : relative_components)
//         Ways += (i*(N-i));
//     // i because I can take any of one friend from one component and all friends of remaining components are able to form pair with that component that's why (N-i)  
//     cout<<"Number of ways in which 2 persons from different groups can be chossen : "<<Ways/2<<endl;
//     // by 2 because remove overcounting
//     return 0;
// }


// Bonus tip -> set size of adjacency list equal to no. of nodes if you want to run out from no output problem