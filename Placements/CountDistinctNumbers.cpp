#include<bits/stdc++.h>
using namespace std; 

#define vi vector<int>
#define vvi vector<vi> 
#define pii pair<int,int>
#define vii vector<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

const int N = 1e5+2;

int a[N], tree[4*N] ={INT_MAX};

void _s_build(int root, int st, int en) {
	if (st == en) {
		tree[root] = a[st];

		return;
	}

	int mid = st + ((en - st) >> 1);

	_s_build(2*root, st, mid);
	_s_build(2*root+1, mid+1, en);

	tree[root] = min(tree[2*root], tree[2*root+1]);
}

int _s_countDistinct(int root, int st, int en, int idx, int val) {
	if (st == en) {
		a[idx] -= val;
		tree[root] -= val;
	
		return 0;
	}

	int mid = st + ((en - st) >> 1), s = 0;

	if (idx <= mid) s += _s_countDistinct(2*root, st, mid, idx, val);
	else s += _s_countDistinct(2*root+1, mid+1, en, idx, val);

	if (tree[2*root+1] < tree[2*root]) return s + 1;

	tree[root] = min(tree[2*root], tree[2*root+1]);

	return s;
}

main() {
	int n, m, x, y; cin >> n >> m;

	for (int i=0; i<n; i++) cin >> a[i];
	
	_s_build(1, 0, n-1);

	for (int i=0; i<m; i++) {
		cin >> x >> y; 

		if (x != 0) x = x-1;
		cout << _s_countDistinct(1, 0, n-1, x, y) + 1 << endl;

		// + 1 because there will be one distinct in very last.
	}

	return 0;
}

/* 

Test Inputs
4 2
5 7 2 4
2 2
4 3
1 1
3
1 1


*/