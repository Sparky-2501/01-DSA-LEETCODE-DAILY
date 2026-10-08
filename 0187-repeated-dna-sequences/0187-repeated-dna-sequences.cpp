class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //substrings of length 10

        unordered_map<string, int> mp;
        vector<string> ans;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            mp[sub]++;

            // repeated string will increase its count 
            if (mp[sub] == 2) {
                ans.push_back(sub);
            }
        }

        return ans;
    }
};