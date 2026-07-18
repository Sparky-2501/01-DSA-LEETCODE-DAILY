class Solution {
public:
    int findGCD(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); // nlogn
        int mn = nums[0], mx = nums[0];
        for (int x : nums) { // O(n)
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return __gcd(mn, mx);
    }
};