class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum1 = 0;
        long long sum2 = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        seg[node].sum2 = (seg[node].sum2 + 2LL * val % MOD * seg[node].sum1 + len % MOD * val % MOD * val) % MOD;

        seg[node].sum1 = (seg[node].sum1 + len % MOD * val) % MOD;
        seg[node].lazy = (seg[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r) return;
        int mid = (l + r) / 2;
        long long val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        seg[node].sum1 = (seg[node * 2].sum1
                        + seg[node * 2 + 1].sum1) % MOD;

        seg[node].sum2 = (seg[node * 2].sum2
                        + seg[node * 2 + 1].sum2) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            update(1, 0, n - 1, prev + 1, i, 1);

            last[nums[i]] = i;

            ans = (ans + seg[1].sum2) % MOD;
        }

        return ans;
        
    }
};