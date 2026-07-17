class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums)
            freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1);

        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];
        }

        // exact[g] = pairs whose gcd is exactly g
        vector<long long> exact(mx + 1);

        for (int g = mx; g >= 1; g--) {
            exact[g] = cnt[g] * (cnt[g] - 1) / 2;

            for (int m = 2 * g; m <= mx; m += g)
                exact[g] -= exact[m];
        }

        // prefix counts
        vector<long long> prefix(mx + 1);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long k : queries) {
            int g = lower_bound(prefix.begin(), prefix.end(), k + 1) -
                    prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};