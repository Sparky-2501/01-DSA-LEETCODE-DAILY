class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int,int>> pA, pB;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) pA.push_back({i, j});
                if (img2[i][j]) pB.push_back({i, j});
            }
        }
        unordered_map<string, int> freq;
        int ans = 0;
        for (auto [x1, y1] : pA) {
            for (auto [x2, y2] : pB) {
                int dx = x2 - x1;
                int dy = y2 - y1;

                string key = to_string(dx) + "," + to_string(dy);
                ans = max(ans, ++freq[key]);
            }
        }
        return ans;
    }
};