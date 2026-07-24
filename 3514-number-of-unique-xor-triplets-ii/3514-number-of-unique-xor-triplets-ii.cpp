class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // Insert every nums[i] into the answer set first.
        //  Then generate (nums[i] ^ nums[j]) ^ nums[k] only for i < j.
        unordered_set<int> ans; // copy all to ans
        unordered_set<int> pairs;

        for (int x : nums)
            ans.insert(x);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                pairs.insert(nums[i] ^ nums[j]); // element 1 & 2
            }
        }

        for (int p : pairs) {
            for (int x : nums) {
                ans.insert(p ^ x);
            }
        }

        return ans.size();
    }
};