class Solution {
public:
    using ull = unsigned long long;
    int n;
    const ull BASE = 131;

    bool check(vector<int>& nums, int k) {
        unordered_map<ull, int> freq;

        ull hash = 0;
        ull power = 1;

        // BASE^(k-1)
        for (int i = 1; i < k; i++) {
            power *= BASE;
        }

        // initial window
        for (int i = 0; i < k; i++) {
            hash = hash * BASE + nums[i];
        }
        freq[hash]++;

        // rolling hash for remaining window
        for (int i = k; i < n; i++) {
            hash -= (ull)nums[i - k] * power;
            hash = hash * BASE + nums[i];

            freq[hash]++;
        }

        // check whether any subarray occurs exactly once
        for (auto& [h, count] : freq) {
            if (count == 1)
                return true;
        }
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();

        int low = 1, high = n;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};