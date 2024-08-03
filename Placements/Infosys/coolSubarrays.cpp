#include<bits/stdc++.h> 
using namespace std;

#define vi vector<int>

int countCoolSubarrays(int n, vi &a) {
	unordered_map<int,int> p;
	int pSum = 0, ans = 0, req;

	p[0] = 1;

	for (int i=0; i<n; i++) {
		pSum += a[i];
		for (int j=0; j*j<=pSum; j++) {
			req = pSum - (j * j);
			if (p.find(req) != p.end()) 
				ans += p[req];
		}
		p[pSum]++;
	}	

	return ans;
}

int main() {	
	int n, te; cin >> n;

	vi a;
	for (int i=0; i<n; i++) {
		cin >> te; a.push_back(te);
	}

	cout << countCoolSubarrays(n, a) << endl; 

	return 0;
}

/*
Rough Sheet

1 4 3 2
1 5 8 10


*/