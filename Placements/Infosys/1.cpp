// 1

#include<bits/stdc++.h>
using namespace std;

#define vb vector<bool>

void _seive(vb &p, int n) {
	p[0] = p[1] = false;

	for (int i=2; i<=n; i++) {
		if (p[i]) {
			for (int j=i*i; j<=n; j+=i) 
				p[j] = false;
		}
	}
}

int minimumPlusXY(int n) {
	if (n < 2) return -1;

	vb prime(n + 1, true);

	_seive(prime, n);

	int sum = INT_MAX;
	int x2, y2, sq;

	for (int i=2; i<=n; i++) {
		if (prime[i]) {
			x2 = i * i;
			y2 = n - x2;

			if (y2 < x2) break;

			sq = sqrt(y2);
			if (sq * sq == y2 and prime[sq])
				sum = min(sum, i + sq);
		}
	}

	return sum == INT_MAX ? -1 : sum;
}

int main() {
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		cout << minimumPlusXY(sqrt(n) + 1) << endl;
	} // complexity : O(/nloglog/n + /n)

	return 0;
}