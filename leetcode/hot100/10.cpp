#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        if(p[0] == '*') return true;

        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        dp[0][0] = true;
        
        auto matches = [&] (int s1, int s2)->bool {
            if(s1 == 0) return false;
            if(p[s2-1] == '.' || s[s1-1] == p[s2-1]) return true;
            return false;
        };

        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j-1] != '*') {
                    if(matches(i, j)) dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i][j-2];
                    if(matches(i, j-1)) {
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};