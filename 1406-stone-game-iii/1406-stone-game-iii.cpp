class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue) {

        // base case when no stone left
        if (i >= stoneValue.size()) {
            return 0;
        }
        if (dp[i] != INT_MIN) {
            return dp[i];
        }

        int take = 0;
        int best = INT_MIN;

        // taking 1, 2, or 3 stones
        for (int k = 0; k < 3 && i + k < stoneValue.size(); k++) {
            take += stoneValue[i + k];
            best = max(best, take - solve(i + k + 1, stoneValue));
        }

        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        dp.assign(stoneValue.size(), INT_MIN);

        int diff = solve(0, stoneValue);

//If the total score was 0 the game is "Tie", and if it has positive value then "Alice" wins, otherwise "Bob" wins.
        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        }
        return "Tie";
    }
};