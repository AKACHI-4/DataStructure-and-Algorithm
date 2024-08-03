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

int MaxDishesRamuPick(int n, vector<int>& a) {
	unordered_map<int, int> mp; 

	int type, i = 0;
	while (i < n-1) {
		type = a[i];
		mp[type] += 1;

		if (type == a[i+1]) 
			i += 1;
		i += 1;
	}
	if (i < n) mp[a[i]] += 1;

	int mx = 0, ans;
	for (auto it : mp) {
		if (mx < it.ss or (mx == it.ss and ans > it.ff)) {
			ans = it.ff;
			mx = it.ss;
		}
	}

	return ans;
}

main() {
	int t;
	cin >> t;

	while (t--) {
		int n, temp; 
		cin >> n;

		vector<int> a;
		rep(i, 0, n) {
			cin >> temp;
			a.push_back(temp);
		}

		cout << MaxDishesRamuPick(n, a) << endl;
	}
}