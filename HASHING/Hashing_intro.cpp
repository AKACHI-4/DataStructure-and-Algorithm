#include<bits/stdc++.h>
using namespace std;

signed main(){
    
    unordered_map<string,int> mp; 

    pair<string,int> p = make_pair("Adarsh",1);

    mp.insert(p);

    cout<<mp["Adarsh"]<<endl; 

    mp["Adarsh"] = 2; 
    
    cout<<mp["Adarsh"]<<endl; 

    cout<<mp["Rawat"]<<endl; 

    cout<<mp["Sukio"]<<endl;

    cout<<mp.at("Sukio")<<endl; 
    
    cout<<mp.size()<<endl; 

    cout<<"Count of ME : "<<mp.count("ME")<<endl;

    cout<<mp.erase("Sukio")<<endl; 

    cout<<"Size of Map : "<<mp.size()<<endl;

    //iterator
    unordered_map <string,int> :: iterator it = mp.begin();
    while (it!=mp.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    /* BUCKET ARRAY */    

    return 0;
}