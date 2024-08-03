#include<bits/stdc++.h>
using namespace std; 

int minimumXY(long long n) { 
	
	unordered_set<long long> st;

	long long x2, y2;
	long ans = LONG_MAX;

	for (int i=2; i<sqrt(n); i++) {
		y2 = i*i; 
		x2 = n - y2;

		if (st.find(x2) != st.end()) {
			ans = sqrt(x2) + i;
			break;
		}
	
		st.insert(y2);
	}

	return ans == LONG_MAX ? -1 : ans;
}

int main() {
	long long n; 
	cin >> n;

	cout << minimumXY(n) << endl;
	return 0;
}