class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return min({ nums[n - 1] - nums[2], nums[n - 2] - nums[1], nums[n - 3] - nums[0]});
    }
};

/*
checking what happens to the minimum and maximum after removing two extreme elements in all three possible combinations.

n-1 & 2 => after remvoing smaller
n-2 & 1 => after removing larger and smaller
n-3 & 0 => after removing largest 

1 4 7 8 5
1 4 5 7 8 
=> 3 3 4
min 3

1 4 3
1 3 4
=> 0 0 0

*/