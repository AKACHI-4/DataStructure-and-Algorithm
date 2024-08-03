#include<bits/stdc++.h>
using namespace std;

// ye bch gya na .. 

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define rep(i,a,b) for(int i=a; i<b; i++)

int minimumCostToDelete(int n, int m, string s, string c, vi &a) {
	vvi dp(n + 1, vi(m + 1, 0));

	rep (i, 1, n + 1) {
		rep (j, 1, m + 1) {
			if (s[i - 1] == c[j - 1])
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << endl;
	rep (i, 0, n + 1) {
		rep (j, 0, m + 1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int ans = INT_MAX;
	rep (i, 0, n + 1)
		ans = min(dp[i][m], ans);

	return ans;
}

int _lcs(int i, int j, string s, string c, vi &a) {
	if (j == c.size()) return 0;
	if (i == s.size() and j < c.size()) return INT_MAX;

	if (s[i] == c[j]) {
		return a[i] + min(_lcs(i+1, j, s, c, a), _lcs(i+1, j+1, s, c, a));
	} else {
		return _lcs(i+1, j, s, c, a);
	}
}

int main() {
	int t; cin >> t;

	while (t--) {
		int n, m, te; cin >> n >> m;
		string s, c; cin >> s >> c;

		vi a;
		rep(i, 0, n) {
			cin >> te; a.push_back(te);
		}

		// cout << n << " " << m << endl;
		// cout << s << " " << c << endl;
		// for (auto av : a) cout << av << " ";
		// cout << endl;
		// cout << endl;

		// cout << minimumCostToDelete(n, m, s, c, a) << endl;
		cout << _lcs(0, 0, s, c, a) << endl;
	}

	return 0;
}