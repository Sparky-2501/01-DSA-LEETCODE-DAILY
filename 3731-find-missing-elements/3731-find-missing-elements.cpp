class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> miss;
        int min_val = nums[0], max_val = nums[0];

        for (int x : nums) {
            min_val = min(min_val, x);
            max_val = max(max_val, x);
        }

        unordered_set<int> s(nums.begin(), nums.end());
        
        for (int i = min_val; i <= max_val; i++) {
            if (s.find(i) == s.end()) {
                miss.push_back(i);
            }
        }
        return miss;
    }
};