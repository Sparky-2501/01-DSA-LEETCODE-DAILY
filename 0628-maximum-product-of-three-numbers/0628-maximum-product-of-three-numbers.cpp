class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
        // prod of 3 largest num
        //  nums[n - 1] * nums[n - 2] * nums[n - 3],
        // prod of 2 smallest (negatives) + largest
        //  nums[0] * nums[1] * nums[n - 1]);
    }
};