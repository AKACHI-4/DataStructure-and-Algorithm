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

long minimumCostToDelete(int n, int m, string s, string c, vector<int>& a) {

	long minimumCost = 0;

	for (int i=0; i<n; i++) { 
		if (s.substr(i, m) == c) {
			minimumCost += a[i];
		}
	}

	return minimumCost;
}
main() { 
	int n, m;
	string s, c;
	vector<int> a;

	cin >> n;
	cin >> m;
	cin >> s;
	cin >> c;

	for (int i=0; i<n ; i++) {
		int val; cin >> val;
		a.push_back(val);
	}

	cout << minimumCostToDelete(n, m, s, c, a) << endl;
}
