class Solution {
public:
    int rows, cols;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1) {
            return;// Out of bounds or water
        }

        // Mark land as visited
        grid[r][c] = 1;

        dfs(r - 1, c, grid); // Up
        dfs(r + 1, c, grid); // Down
        dfs(r, c - 1, grid); // Left
        dfs(r, c + 1, grid); // Right
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // Step 1: Remove boundary-connected islands
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] == 0)
                dfs(r, 0, grid);

            if (grid[r][cols - 1] == 0)
                dfs(r, cols - 1, grid);
        }

        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0)
                dfs(0, c, grid);

            if (grid[rows - 1][c] == 0)
                dfs(rows - 1, c, grid);
        }

        // Step 2: Count remaining islands
        int count = 0;

        for (int r = 1; r < rows - 1; r++) {
            for (int c = 1; c < cols - 1; c++) {
                if (grid[r][c] == 0) {
                    count++;
                    dfs(r, c, grid);
                }
            }
        }
        return count; 
    }
};