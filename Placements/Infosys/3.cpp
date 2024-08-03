// 3

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define rep(i,a,b) for(int i=a; i<b; i++)

int chooseDishes(int n, int tp, vi &a) {
	int d, cnt = INT_MIN, c;

	rep (t, 1, tp + 1) {

		c = 0;
		rep (i, 0, n) {
			if (a[i] == t) {
				c += 1; i += 1;
			}
		}

		if (c > cnt) {
			cnt = c;
			d = t; // complexity : O(t * n * type of dishes) ~ O(t * n^2) ~ O(10^9)
		}
	}

	return d;
}

int main() {
	int t; cin >> t;

	while (t--) {
		int n, te; cin >> n;
		unordered_set<int> us;

		vi a;
		rep(i, 0, n) {
			cin >> te; 
			a.push_back(te);
			us.insert(te);
		}

		if (us.size() == 1) cout << *us.begin() << endl;
		else cout << chooseDishes(n, us.size(), a) << endl;
	}

	return 0;
}

/*
Constraints :
• 1<=T<=10^3
• 1 <= N <= 10^3
• 1<=Ai<=10^3
*/