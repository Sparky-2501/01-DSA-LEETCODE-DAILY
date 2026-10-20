class Solution {
public:
    bool isRotation(vector<int>& nums, vector<int>& sortedNums, int start,
                    int k) {
        // Pattern: corresponding block in sorted array
        vector<int> pattern(k);
        for (int i = 0; i < k; i++) {
            pattern[i] = sortedNums[start + i];
        }

        // Build KMP prefix function
        vector<int> lps(k, 0);
        for (int i = 1, len = 0; i < k;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search pattern in the original block repeated twice.
        // Length 2*k - 1 is enough to check every rotation.
        int j = 0;
        for (int i = 0; i < 2 * k - 1; i++) {
            int x = nums[start + (i % k)];

            while (j > 0 && x != pattern[j]) {
                j = lps[j - 1];
            }
            if (x == pattern[j]) {
                j++;
            }
            if (j == k) {
                return true;
            }
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        // 1 extra sorted copy [1,2,3]
        // divide into divisor of k
        // check for cylindrical rotation and copy array
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long ans = 0;
        for (int k = 1; k <= n; k++) { //list only divisors
            if (n % k != 0) {
                continue;
            }
            bool valid = true;
            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sortedNums, start, k)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans += k;
            }
        }
        return ans;
    }
};