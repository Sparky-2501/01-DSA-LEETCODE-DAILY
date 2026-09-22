class Solution {
    struct Node {
        int prod = 1;
        array<int, 5> cnt{};
        Node() {}
    };
    int k;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;
        res.prod = (long long)a.prod * b.prod % k;
        for (int r = 0; r < k; r++) {
            // Prefix lies completely in left
            res.cnt[r] += a.cnt[r];
            // Whole left + prefix of right
            int nr = (long long)a.prod * r % k;
            res.cnt[nr] += b.cnt[r];
        }
        return res;
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        // segment tree + modular product tracking.
        this->k = k;
        int n = nums.size();
        // Iterative segment tree
        int sz = 1;
        while (sz < n)
            sz <<= 1;

        vector<Node> tree(2 * sz);
        // Build leaves
        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;
            tree[sz + i].prod = r;
            tree[sz + i].cnt[r] = 1;
        }

        // Build tree
        for (int i = sz - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i << 1], tree[i << 1 | 1]);
        }

        auto update = [&](int pos, int val) {
            int p = sz + pos;
            tree[p] = Node();

            int r = val % k;
            tree[p].prod = r;
            tree[p].cnt[r] = 1;

            p >>= 1;
            while (p) {
                tree[p] = mergeNode(tree[p << 1], tree[p << 1 | 1]);
                p >>= 1;
            }
        };

        auto query = [&](int l) {
            // Query [l, n)
            int left = sz + l;
            int right = sz + n;

            Node L, R;
            while (left < right) {
                if (left & 1)
                    L = mergeNode(L, tree[left++]);
                if (right & 1)
                    R = mergeNode(tree[--right], R);
                left >>= 1;
                right >>= 1;
            }

            return mergeNode(L, R);
        };

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            update(index, value);
            // Get nums[start ... n-1]
            Node res = query(start);
            // Only NON-EMPTY remaining arrays count
            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};