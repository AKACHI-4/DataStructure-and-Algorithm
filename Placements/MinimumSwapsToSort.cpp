/* prerequisties :  min swaps to sort the distinct array */

#include<bits/stdc++.h>
using namespace std; 

#define vi vector<int>
#define vvi vector<vi> 
#define pii pair<int,int>
#define vii vector<pair> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

const int N = 1e5+2;

long findMinimumSwapMaximumScore(int n, vector<int>& arr) {
	vector<int> temp = arr; 
	sort(temp.begin(), temp.end()); 

	unordered_map<int, int> mp;
	for (int i=0; i<n/2; i++)
		mp[temp[i]] = temp[n-i-1];

	unordered_map<int, int> g;
	for (int i=0; i<n; i+=2) {
		int a = max(arr[i], arr[i+1]);
		int b = min(arr[i], arr[i+1]);

		g[a] = b;
	}
	
	unordered_set<int> s;

	long ans = 0;
	for (auto& it : g) {
		int src = it.ff, dest = it.ss;

		if (s.find(src) != s.end()) continue;
        
		int cycle = 0;
		while (s.find(src) == s.end()) {
			s.insert(src);
			
			src = mp[dest];
			dest = g[src];
			
			cycle += 1;
		}

		ans += (cycle - 1);
	}

	return ans;
}

main() {
	int n, temp; 
	vector<int> arr;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> temp; 
		arr.push_back(temp); 
	}

	cout << findMinimumSwapMaximumScore(n, arr) << endl;
}
