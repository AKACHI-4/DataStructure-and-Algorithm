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

bool CanWeMoveStonesInPiles(int a, int b, int c, int x, int y) {
	if (a+b+c != x+y) {
		return false;
	}

	if (y < min({a, b, c}) or x < min({a, b, c})) {
		return false; 
	} 
	
	return true;
}

main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;

		if (CanWeMoveStonesInPiles(a, b, c, x, y)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

/* seeing test case is important tho */