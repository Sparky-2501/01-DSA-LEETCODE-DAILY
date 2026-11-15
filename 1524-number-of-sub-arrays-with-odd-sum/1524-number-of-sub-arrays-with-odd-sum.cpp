class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // prefix sum + parity
        const int MOD = 1e9 + 7;
        long long even = 1, odd = 0, sum = 0, ans = 0;

        for (int x : arr) {
            sum += x;
            if (sum % 2 == 1) {
                ans = (ans + even) % MOD;
                odd++;
            } else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }
        return ans;
    }
};