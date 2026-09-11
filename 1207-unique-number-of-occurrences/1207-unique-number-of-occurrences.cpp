class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        // Count frequency of each number
        for (int x : arr) {
            freq[x]++;
        }
        // Store frequencies in a set
        unordered_set<int> occurrences;
        for (auto& [num, count] : freq) {
            occurrences.insert(count);
        }
        // Check if all frequencies are unique
        return freq.size() == occurrences.size();
    }
};