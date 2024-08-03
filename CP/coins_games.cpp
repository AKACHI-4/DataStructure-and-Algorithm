#include <bits/stdc++.h>
using namespace std;

int f(string s) {
    if (s.length() <= 1) {
        return 0;
    }

    int maxi = 0;
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
        dp[i][i] = true; 

    // Fill the DP table
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1; 

            cout << i << " " << j << " " << length << endl;

            if (s[i] == s[j] || s[i] == '?' || s[j] == '?') {
                if (length == 2) { 
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                
                if (dp[i][j] && length % 2 == 0) {
                    maxi = max(maxi, length);
                }
            }
        }

        cout << endl;
    }

    return maxi;
}

int main() {
    string s;
    cin >> s;
    cout << f(s) << endl;
    return 0;
}