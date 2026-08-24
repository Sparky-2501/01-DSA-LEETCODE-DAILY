class Solution {
public:
    bool divisorGame(int n) {
        /*
        a-1,3,5,7,9
        b-2,4,6,8,10

        n % x ==0
        10 % 1,2,5 == 0
        9 % 1,3 == 0

        n-x = 10-2 / 10-5
        n-x = 9-3

        move compulsory

        */

        // for all even alice wins

        return n % 2 == 0;
    }
};