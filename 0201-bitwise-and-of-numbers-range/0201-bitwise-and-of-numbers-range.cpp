class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // bitwise in l & r
        int shift = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};