class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        /*
       mx =loop(i)-> max(num[0-i])
        array prefixGcd = [ gcd (nums[i] , mx )   ]

        sort prefix
        gcd of (pairs (small and large))

        */
        vector<int> prefixGcd;
        
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            prefixGcd.push_back(gcd(x, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};