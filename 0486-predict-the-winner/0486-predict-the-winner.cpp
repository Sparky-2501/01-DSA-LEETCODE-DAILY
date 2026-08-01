class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<int> dp(nums);

        for (int len = 2; len <= nums.size(); len++) {
            for (int j = nums.size() - 1; j >= len - 1; j--) {
                int i = j - len + 1;
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[nums.size() - 1] >= 0;
    }
};