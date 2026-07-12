class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //sort +copy
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        // ranks assign for sorted
        for (int num : sorted) {
            if (rank.find(num) == rank.end()) {
                rank[num] = r++;
            }
        }

        // Replace element with rank
        vector<int> ans;
        for (int num : arr) {
            ans.push_back(rank[num]);
        }

        return ans;
    }
};