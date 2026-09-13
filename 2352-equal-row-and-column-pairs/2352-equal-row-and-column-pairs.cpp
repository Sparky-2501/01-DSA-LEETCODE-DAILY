class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); //3

        map<vector<int>, int> mp;
        // Store all rows
        for (int i = 0; i < n; i++) {
            mp[grid[i]]++;  //[3,2,1] .....
        }

        int ans = 0;
        // Create each column and check in map
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);  //[3,1,2]....
            }
            if (mp.count(col)) {
                ans += mp[col];
            }
        }

        return ans;
    }
};