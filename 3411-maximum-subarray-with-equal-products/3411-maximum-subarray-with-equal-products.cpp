
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = min(n, 2);

        for (int left = 0; left < n; left++) {
            for (int right = left + 2; right < n; right++) {
                bool valid = true;
                for (int i = left; i <= right; i++) {
                    for (int j = i + 1; j <= right; j++) {
                        if (gcd(nums[i], nums[j]) != 1) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }

                if (!valid) break;
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};

