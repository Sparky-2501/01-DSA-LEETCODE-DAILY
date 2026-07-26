class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        /*
        check for slope:
        (y2-y1 / x3-x1 ) == (y3-y1 / x3-x1 )

        (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1) != 0
        */
        int term1 = (points[1][0] - points[0][0]) * (points[2][1] - points[0][1]);
        int term2 = (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
        //term1 - term2 = 0 -> slope 45 deg -> same line
        return  term1 - term2 !=0;
    }
};