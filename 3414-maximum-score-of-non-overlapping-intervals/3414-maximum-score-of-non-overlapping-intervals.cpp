class Solution {
public:
    struct Node {
        long long score = 0;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.ids < b.ids;   // lexicographical comparison
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({ intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        // Sort by end time
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<long long> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        /*
            prev[i] = number of intervals before i
                      whose end < start[i]
            Thus if we take interval i, we jump to prev[i].
        */
        vector<int> prev(n);
        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(ends.begin(), ends.begin() + i, a[i][0])
                - ends.begin();
        }

        /*
            dp[k][i] = best answer using EXACTLY k intervals
                       among the first i intervals.
            This is important: don't mix "at most k" states when
            deciding the lexicographical tie.
        */
        const long long NEG = -(1LL << 60);
        vector<vector<Node>> dp(5, vector<Node>(n + 1));

        // Mark impossible exact-count states.
        for (int k = 1; k <= 4; k++) {
            for (int i = 0; i <= n; i++) {
                dp[k][i].score = NEG;
            }
        }

        // Exactly 0 intervals => score 0, empty list.
        for (int i = 0; i <= n; i++) {
            dp[0][i].score = 0;
        }

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {

                // 1. Don't take interval i-1
                Node best = dp[k][i - 1];
                // 2. Take interval i-1
                int j = prev[i - 1];

                if (dp[k - 1][j].score != NEG) {
                    Node take = dp[k - 1][j];
                    take.score += a[i - 1][2];
                    int idx = (int)a[i - 1][3];

                    // Keep original indices sorted.
                    take.ids.insert(
                        lower_bound(  take.ids.begin(),  take.ids.end(),  idx),idx);
                    if (better(take, best))
                        best = take;
                }
                dp[k][i] = best;
            }
        }
        /*
            We can choose AT MOST 4 intervals.
            Compare answers containing 1,2,3,4 intervals.
        */
        Node ans;
        ans.score = 0;

        for (int k = 1; k <= 4; k++) {
            if (better(dp[k][n], ans))
                ans = dp[k][n];
        }
        return ans.ids;
    }
};
