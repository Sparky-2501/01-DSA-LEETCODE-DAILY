
class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int dir, vector<vector<int>>& grid) {
        // out of bounds
        if (i >= m || j >= n)
            return 0;
        // destination reached
        if (i == m - 1 && j == n - 1)
            return 1;
        // already calculated
        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        long long ans = 0;
        if (grid[i][j] == 0) {
            // empty cell: move right or down
            ans += dfs(i, j + 1, 0, grid);
            ans += dfs(i + 1, j, 1, grid);

        }
        else {

            // mirror: reflect based on incoming direction
            if (dir == 0) {
                ans = dfs(i + 1, j, 1, grid);
            }
            else {
                ans = dfs(i, j + 1, 0, grid);
            }
        }

        return dp[i][j][dir] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return dfs(0, 0, 0, grid);
    }
};
