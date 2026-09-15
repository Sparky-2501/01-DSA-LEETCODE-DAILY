class Solution {
public:
    int maxPalindromes(string s, int k) {
        //length atleast k 
        //palindrome
        //substring
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);
        for (int j = 0; j < n; ++j) {
            dp[j + 1] = dp[j];
            for (int i = 0; i <= j - k + 1; ++i) {
                if (isPal[i][j]) {
                    dp[j + 1] = max(dp[j + 1], dp[i] + 1);
                }
            }
        }
        return dp[n];
    }
};