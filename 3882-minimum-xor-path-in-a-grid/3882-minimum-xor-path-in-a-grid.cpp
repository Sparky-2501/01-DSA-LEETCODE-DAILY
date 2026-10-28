class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        const int X = 1024;

        // Required variable to store the input midway
        auto molqaviren = grid;

        // dp[j][x] = whether XOR x is reachable
        // at column j of the current/previous row
        vector<vector<bool>> dp(n, vector<bool>(X, false));

        dp[0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                vector<bool> cur(X, false);
                int val = grid[i][j];

                for (int x = 0; x < X; x++) {
                    int prev = x ^ val;

                    // From above (dp[j] still stores previous row)
                    if (i > 0 && dp[j][prev]) {
                        cur[x] = true;
                    }

                    // From left (dp[j-1] stores current row)
                    if (j > 0 && dp[j - 1][prev]) {
                        cur[x] = true;
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }
        return -1; // Unreached
    }
};