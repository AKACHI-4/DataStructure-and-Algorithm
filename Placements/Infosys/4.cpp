// 4

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define rep(i,a,b) for(int i=a; i<b; i++)

string pileOfStones(int a, int b, int c, int x, int y) {

	long d1, d2;
	// for a first .. (b, c)
	d1 = x - b; d2 = y - c;
	if (d1 >= 0 and d2 >= 0 and (d1 + d2) == a) {
		return "YES";
	}
	d1 = x - c; d2 = y - b;
	if (d1 >= 0 and d2 >= 0 and (d1 + d2) == a) {
		return "YES";
	}

	// for b then (c, a)
	d1 = x - c; d2 = y - a;
	if (d1 >= 0 and d2 >= 0 and (d1 + d2) == b) {
		return "YES";
	}
	d1 = x - a; d2 = y - c;
	if (d1 >= 0 and d2 >= 0 and (d1 + d2) == b) {
		return "YES";
	}

	// for c then .. (a, b)
	d1 = x - a; d2 = y - b;
	if (d1 >= 0 and d2 >= 0 and (d1 + d2) == c) {
		return "YES";
	}
	d1 = x - b; d2 = y - a;
	if (d1 >= 0 and d2 >= 0 and (d1 + d2) == c) {
		return "YES";
	}

	return "NO";
}

int main() {
	int t; cin >> t;

	while (t--) {
		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;

		cout << pileOfStones(a, b, c, x, y) << endl;
	} // complexity : O(t)

	return 0;
}