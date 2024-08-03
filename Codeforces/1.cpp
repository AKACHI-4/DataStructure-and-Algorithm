#include<bits/stdc++.h>
using namespace std; 

string newPassword(string s) {
	int n = s.size();

	for (int i=1; i<n; i++) {
		if (s[i] == s[i-1]) {
			string t = s.substr(0,i);

			if (s[i] == 'z') t.push_back(s[i] - 1);
			else t.push_back(s[i] + 1);

			return t + s.substr(i);
		}
	}

	if (s[n-1] == 'z') s.push_back(s[n-1] - 1);
	else s.push_back(s[n-1] + 1);

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
