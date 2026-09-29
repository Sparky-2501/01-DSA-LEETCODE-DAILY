class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // A valid parentheses string must be with even length.
        if ((m + n - 1) % 2 != 0) return false;

        // dp[j] = set of possible balance values at current row/column.
        vector<unordered_set<int>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> cur;

                int val = (grid[i][j] == '(' ? 1 : -1);

                if (i == 0 && j == 0) {
                    if (val == 1) cur.insert(1);
                } else {
                    // From top
                    if (i > 0) {
                        for (int bal : dp[j]) {
                            if (bal + val >= 0)
                                cur.insert(bal + val);
                        }
                    }

                    // From left part
                    if (j > 0) {
                        for (int bal : dp[j - 1]) {
                            if (bal + val >= 0)
                                cur.insert(bal + val);
                        }
                    }
                }

                dp[j] = move(cur);
            }
        }
        // Valid string must end with balance 0.
        return dp[n - 1].count(0);
    }
};