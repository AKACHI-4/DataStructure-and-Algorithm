#include<bits/stdc++.h>
using namespace std; 

#define vi vector<int>

int evenPositions(string s, int n) {

	vi closings(n, n-1);

	for (int i=n-2; i>=0; i--) {
		if (s[i] == ')') closings[i] = i;
		else closings[i] = closings[i+1];
	}

	int cost = 0;
	for (int i=0; i<n; i++) {

		if (s[i] == '_') {
			cost += closings[i] - i;
		} else if (s[i] == '(') {
			cost += 1;
			i++;
		}
	}

	return cost;
}

int main() {
	int sz; cin >> sz;

	int n; string s;
	while (sz--) {
		cin >> n;
		cin >> s;

		cout << evenPositions(s, n) << endl;
	}


	return 0;
}
