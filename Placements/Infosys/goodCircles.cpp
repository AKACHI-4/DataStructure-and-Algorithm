#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

bool goodCircles(int c) {	

	int a, b, b2;
	for (a=1; a<=sqrt(c); a++) {
		b2 = c - (a*a);

		if (b2 <= 0) continue;

		b = int(sqrt(b2));
		if (b*b == b2)
			return true;
	}

	return false;
}

int main() {
	int n, te, c = 0; cin >> n;

	vi arr;
	for (int i=0; i<n; i++) {
		cin >> te;

		if (goodCircles(te))
			c += 1;
	}

	cout << c << endl;

	return 0;
}