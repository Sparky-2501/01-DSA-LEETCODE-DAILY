class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto& r : reservedSeats) { 
            mp[r[0]].insert(r[1]);
        }

        /*
        1 -> {2,7}
        2 -> {3}

        from n only 2 used other left and can feel 2 families 
        */
        int ans = (n - mp.size()) * 2;

        for (auto& [row, seats] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int s = 2; s <= 5; s++) {
                if (seats.count(s))
                    left = false;   // 2,3,4,5
            }

            for (int s = 4; s <= 7; s++) {
                if (seats.count(s))
                    middle = false; // 4,5,6,7
            }
        
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s))
                    right = false;  // 6,7,8,9
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};