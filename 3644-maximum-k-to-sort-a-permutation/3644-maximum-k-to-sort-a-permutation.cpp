class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        //permutation of 0 to n-1 so direct loop from 0 to n-1 
        
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            //l1: ans = -1    : -1 & num = num
            //l2: ans = 3 
            //l3: ans = 3
            //l4: ams = 1
            if (nums[i] != i) {
                ans &= nums[i];  
            }
        }
        
        return max(ans, 0);
    }
};