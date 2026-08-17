class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> ans(candies.size(),true);
        int currMax = INT_MIN;

        for(int i=0 ; i< candies.size() ; i++){
            currMax = max(currMax , candies[i]);
        }
        
        for(int i=0; i<candies.size() ; i++){
            if(candies[i] + extraCandies  < currMax){
                ans[i] = false;
            }
        }

        return ans;
    }
};