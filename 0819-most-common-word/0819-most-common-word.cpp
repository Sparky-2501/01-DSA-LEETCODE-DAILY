class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        /*
        Convert para into lowercase.
        Extract words only
        Skip banned
        Count frequencyg(hash map.)
        Return highest frequency
        */
         unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";
        string ans = "";
        int maxFreq = 0;

        paragraph += ' ';   // Sentinel to process the last word

        for (char &c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (!ban.count(word)) {
                    freq[word]++;
                    if (freq[word] > maxFreq) {
                        maxFreq = freq[word];
                        ans = word;
                    }
                }
                word.clear();
            }
        }

        return ans;
    }
};