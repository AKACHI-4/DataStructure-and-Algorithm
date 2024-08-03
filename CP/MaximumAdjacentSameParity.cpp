#include<bits/stdc++.h> 
using namespace std; 

string maximumNumberAdjacentSameParity(string str) {
	int n = str.size(); 

	vector<int> nums; 
	for (auto c : str) 
		nums.push_back(c - '0');

	vector<vector<int>> parities;

	int l = 0, r; 
	while (l < n) {
		r = l; 

		vector<int> temp;

		while (r < n-1 and nums[r] % 2 == nums[r+1] % 2) {
			temp.push_back(nums[r]);
			r += 1;
		}
		temp.push_back(nums[r]);

		sort(temp.begin(), temp.end(), greater<int>());

		parities.push_back(temp);

		l = r + 1;
	}

	string ans = "";
	for (const auto& v : parities) {
		for (auto val : v)	
			ans += (val + '0');
	}

	return ans;
}

main() { 
	string s; 
	cin >> s;

	cout << maximumNumberAdjacentSameParity(s) << endl;
}