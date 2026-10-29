class Solution {
    using ll = long long;

    struct Fenwick {
        int n;
        vector<int> bit;
        Fenwick(int n) : n(n), bit(n + 1, 0) {}
        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] ^= val;
                idx += idx & -idx;
            }
        }

        void rangeXor(int l, int r, int delta) {
            add(l + 1, delta);
            add(r + 2, delta);
        }

        int pointQuery(int pos) {
            int ans = 0;
            for (int idx = pos + 1; idx > 0; idx -= idx & -idx) {
                ans ^= bit[idx];
            }
            return ans;
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> pref(n, 0);

        auto getBit = [](char c) { return 1 << (c - 'a'); };

        // Iterative DFS to avoid recursion stack overflow.
        // exit = false: enter node
        // exit = true : finish subtree
        vector<tuple<int, int, bool>> st;
        st.push_back({0, 0, false});

        int timer = 0;

        while (!st.empty()) {
            auto [u, p, exit] = st.back();
            st.pop_back();

            if (exit) {
                tout[u] = timer - 1;
                continue;
            }

            up[0][u] = p;
            depth[u] = (u == 0 ? 0 : depth[p] + 1);

            pref[u] = (u == 0 ? 0 : pref[p]) ^ getBit(s[u]);

            tin[u] = timer++;

            st.push_back({u, p, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (v == p)
                    continue;

                st.push_back({v, u, false});
            }
        }

        // Binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        // Lowest Common Ancestor
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k)) {
                    u = up[k][u];
                }
            }

            if (u == v)
                return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        Fenwick fw(n);
        vector<bool> answer;

        for (const string& q : queries) {
            string type, a, b;
            stringstream ss(q);
            ss >> type >> a >> b;

            if (type == "update") {
                int u = stoi(a);
                char c = b[0];

                // Character parity difference
                int delta = getBit(s[u]) ^ getBit(c);

                if (delta != 0) {
                    // Every prefix in u's subtree changes by delta
                    fw.rangeXor(tin[u], tout[u], delta);
                }

                s[u] = c;
            } else {
                int u = stoi(a);
                int v = stoi(b);

                int w = lca(u, v);

                // Current root-to-node prefix masks
                int pu = pref[u] ^ fw.pointQuery(tin[u]);
                int pv = pref[v] ^ fw.pointQuery(tin[v]);

                // Recover the mask of the complete u-to-v path
                int mask = pu ^ pv ^ getBit(s[w]);

                // Zero or one set bit means palindrome is possible
                answer.push_back((mask & (mask - 1)) == 0);
            }
        }
        return answer;
    }
};