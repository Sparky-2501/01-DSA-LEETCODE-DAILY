class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        // sliding window + deque
        long long ans = 0;
        deque<pair<int, int>> dq;
        int n = nums.size();
        int j = n - 1;
        int i = j;
        long long opr = 0;
        while (i >= 0) {
            int element = nums[i];
            int popCount = 0;

            while (!dq.empty() && dq.front().first <= element) {
                opr += 1LL * (element - dq.front().first) * dq.front().second;
                popCount += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({element, popCount + 1});

            if (opr <= k) {
                ans += 1LL * (j - i + 1);
            } else {
                while (i < j && opr > k) {
                    int bottomVal = dq.back().first;
                    int bottomCount = dq.back().second;
                    opr -= (bottomVal - nums[j]);
                    dq.pop_back();
                    if (bottomCount - 1 > 0) {
                        dq.push_back({bottomVal, bottomCount - 1});
                    }
                    j--;
                }
                ans += 1LL * (j - i + 1);
            }
            i--;
        }
        return ans;
    }
};