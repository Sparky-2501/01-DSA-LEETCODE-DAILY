class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // reduce the largest difference first to get minimum
        long long k = 1LL * k1 + k2;
        vector<long long> diff(nums1.size());
        long long maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (total == 0) return 0;

        //eliminate all differences
        if (k >= total) return 0;

        // binary search for the minimum achievable maximum difference.
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long ops = 0;

            for (long long d : diff) {
                if (d > mid) {
                    ops += d - mid;
                }
                if (ops > k) break;
            }

            if (ops <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long x = low;
        long long used = 0;
        long long ans = 0;

        // Reduce all differences greater than x down to x.
        for (long long d : diff) {
            if (d > x) {
                used += d - x;
                d = x;
            }
            ans += d * d;
        }

        //remaining operations reduce some x to x - 1.
        long long remaining = k - used;

        // each reduction decreases the square by 2*x - 1.
        ans -= remaining * (2 * x - 1);
        return ans;
    }
};