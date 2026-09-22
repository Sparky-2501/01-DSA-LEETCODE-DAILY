class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // Overlap
            if (intervals[i][0] < prevEnd) {
                removed++;
            } else {
                // No overlap, keep this interval
                prevEnd = intervals[i][1];
            }
        }

        return removed;
    }
};