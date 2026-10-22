class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
        int ans = INT_MAX;

        // Case 1: nums is a rotation of [0, 1, ..., n-1]
        int shift = nums[0];
        bool increasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (shift + i) % n) {
                increasing = false;
                break;
            }
        }

        if (increasing) {
            ans = min(ans, (n - shift) % n);
            ans = min(ans, shift + 2);
        }

        // Case 2: nums is a rotation of [n-1, ..., 1, 0]
        int start = nums[0];
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (start - i + n) % n) {
                decreasing = false;
                break;
            }
        }

        if (decreasing) {
            int zeroPos = (n - 1 - start + n) % n;
            ans = min(ans, 1 + min(zeroPos, (n - zeroPos) % n));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};