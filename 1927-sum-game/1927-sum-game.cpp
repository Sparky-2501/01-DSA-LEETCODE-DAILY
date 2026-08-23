class Solution {
public:
    bool sumGame(string num) {
        /*
        lefthalf == righthalf ? bob win : alice
        
        */
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';

            if (num[n - 1 - i] == '?')
                rightQ++;
            else
                rightSum += num[n - 1 - i] - '0';
        }

        int qDiff = leftQ - rightQ;
        int sumDiff = leftSum - rightSum;

        // alice started so moves = 1 3 5 7 9 
        //Odd number of '?' -> Alice gets the final move
        if ((leftQ + rightQ) % 2)
            return true;

        // Bob can win only if the existing difference can
        // exactly compensate for the '?' difference.
        return sumDiff != -9 * qDiff / 2;
    }
};