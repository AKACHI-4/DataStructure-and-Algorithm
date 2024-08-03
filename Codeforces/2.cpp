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

string newPassword(string s) {
	int n = s.size();

	if (n == 1) {
		s.push_back(s[n-1] + 1);

		return s;
	}

	for (int i=1; i<n; i++) {
		if (s[i] == s[i-1]) {
			string t = s.substr(0,i);

			t.push_back(s[i] + 1);

			return t + s.substr(i);
		}
	}

	s.push_back(s[n-1] + 1);

	return s;
}

int main() {
	int n; cin >> n;

	while (n--) {
		string str; cin >> str;

		cout << newPassword(str) << endl;
	}


	return 0;
}
