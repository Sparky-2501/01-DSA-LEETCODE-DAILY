class Solution {
public:
    static const int MOD = 1e9 + 7;
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(k + 1, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i)
            dp[0][i] = 1;

        for (int j = 1; j <= k; ++j) {
            long long prefix = 0;

            for (int i = 1; i < n; ++i) {
                prefix = (prefix + dp[j - 1][i - 1]) % MOD;
                dp[j][i] = (dp[j][i - 1] + prefix) % MOD;
            }
        }

        return dp[k][n - 1];
    }
};