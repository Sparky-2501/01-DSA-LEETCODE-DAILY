class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // Prefix Sum + DP
        const int INF = 1e9;
        // best[i] = shortest target-sum subarray in arr[0..i-1]
        vector<int> best(arr.size() + 1, INF);
        int ans = INF, left = 0, sum = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];
            while (sum > target && left <= right) {
                sum -= arr[left++];
            }
            // Carry forward the best answer seen so far.
            best[right + 1] = best[right];
            if (sum == target) {
                int len = right - left + 1;
                // best[left] represents a subarray completely before 'left'.
                if (best[left] != INF) {
                    ans = min(ans, len + best[left]);
                }
                // This subarray can be the best one for future subarrays.
                best[right + 1] = min(best[right + 1], len);
            }
        }
        return ans == INF ? -1 : ans;
    }
};