class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        /*SOLUTION -1
        vector<int> ans1, ans2;
        for (int x : nums1) {
            if (find(nums2.begin(), nums2.end(), x) == nums2.end()) {
                if (find(ans1.begin(), ans1.end(), x) == ans1.end())
                    ans1.push_back(x);
            }
        }
        for (int x : nums2) {
            if (find(nums1.begin(), nums1.end(), x) == nums1.end()) {
                if (find(ans2.begin(), ans2.end(), x) == ans2.end())
                    ans2.push_back(x);
            }
        }
        return {ans1, ans2};
        */
       
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> a, b;

        for (int x : s1) {
            if (s2.find(x) == s2.end()) {
                a.push_back(x);
            }
        }

        for (int x : s2) {
            if (s1.find(x) == s1.end()) {
                b.push_back(x);
            }
        }

        return {a, b};
    }
};