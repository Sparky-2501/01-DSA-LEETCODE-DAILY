class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);
            // Start a new subarray with just nums[i].
            ndp[num % k]++;

            // Extend every subarray ending at the previous index.
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;
                int nr = (long long)r * num % k;
                ndp[nr] += dp[r];
            }
            // Every subarray ending here contributes to the ans
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }
            dp.swap(ndp);
        }
        return ans;
    }
};