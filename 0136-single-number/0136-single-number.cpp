class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i:nums){
            x = x ^ i; 
        }
        return x;
    }
};


/*
a ^ a = 0
a ^ 0 = a
------------------
0^4 = 4     0000 ^ 0100 = 0100 
4^1 = 5     0100 ^ 0001 = 0101 
5^2 = 7     0101 ^ 0010 = 0111
7^1 = 6     0111 ^ 0001 = 0110
6^2 = 4     0110 ^ 0010 = 0100 
=> 4
*/