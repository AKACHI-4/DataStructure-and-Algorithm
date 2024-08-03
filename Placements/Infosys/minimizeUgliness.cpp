#include<bits/stdc++.h> 
using namespace std;

#define vi vector<int>

void swap(string &s, int i, int j) {
	char c = s[i];
	s[i] = s[j];
	s[j] = c;
}

int minimizeUgliness(int n, string &s, int cash, int a, int b) {
	int o = 0, z = n - 1;

	while (true) {
		while (o < n && s[o]=='0') o++;
		while (z >= 0 && s[z]=='1') z--;

		if (o >= z or cash < a) break;

		swap(s, o, z);

		cash -= a;
		o++; z--;
	}

	cout << cash << " : " << o << ", " << z << " : " << s << endl;

	while (o < n and cash >= b) {
		if (s[o] == '1') {
			s[o] = '0';
			cash -= b;
		}

		o += 1;
	}

	cout << cash << " : " << o << ", " << z << " : " << s << endl;

	return stoi(s, nullptr, 2);
}

int main() {	
	int n, te; cin >> n;

	string s; cin >> s; 
	int cash; cin >> cash;

	int a, b; cin >> a >> b;

	cout << minimizeUgliness(n, s, cash, a, b) << endl; 

	return 0;
}
