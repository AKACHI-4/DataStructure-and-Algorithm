#include <bits/stdc++.h>
using namespace std; 

int CountMergeOperations(vector<int>& v, int n) { 
	int l=0, r=n-1; 
	int mergeCnt = 0;

	while(l <= r) { 
		if(v[l] > v[r]) {
			r--; 
			v[r] += v[r+1];
			mergeCnt++;
		} else if(v[l] < v[r]) {
			l++; 
			v[l] += v[l-1];
			mergeCnt++;
		} else {
			l++; 
			r--;
		}		
	}

	return mergeCnt;
}

int main() {
	int t;
	cin>>t; 

	while(t--){ 
		int n; cin>>n; 
		vector<int> vec; 

		for(int i=0; i<n; i++) {
			int val; cin>>val; 
			vec.push_back(val);
		}

		cout<<CountMergeOperations(vec, n)<<endl;
	}

	return 0;
}