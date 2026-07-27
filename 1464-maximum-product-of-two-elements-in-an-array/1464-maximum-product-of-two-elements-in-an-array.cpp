class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() <= 1){
            return -1;
        }
        
        sort(nums.begin() , nums.end());

        int i = nums[nums.size()-1], j=nums[nums.size()-2];

        return (i-1)*(j-1);
    }
};