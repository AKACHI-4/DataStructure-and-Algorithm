#include<bits/stdc++.h> 
using namespace std; 

int findEleOccurOnce(vector<int> v, int n) {

	for(int i=0; i<n; i++) {
		;
	}

}
int main() { 
	int t; 
	cin>>t; 
	while(t--) { 
		int n;
		cin>>n; 

		vector<int> v; 

		for(int i=0; i<n; i++) {
			int val; cin>>val;
			v.push_back(val);
		}

		cout<<findEleOccurOnce(v, n)<<endl;
	}

	return 0;
}

