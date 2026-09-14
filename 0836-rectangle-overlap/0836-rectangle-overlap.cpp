class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1's left < rec2's right
        // rec2's left < rec1's right
        // rec1's bottom < rec2's top
        // rec2's bottom < rec1's top
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] &&
               rec2[1] < rec1[3];
    }
};