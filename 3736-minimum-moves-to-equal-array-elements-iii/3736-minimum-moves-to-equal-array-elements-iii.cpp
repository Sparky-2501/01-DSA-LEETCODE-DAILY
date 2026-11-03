class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxele = *max_element(nums.begin(), nums.end());

        int moves = 0;

        for (int num : nums) {
            moves += maxele - num;
        }

        return moves;
    }
};