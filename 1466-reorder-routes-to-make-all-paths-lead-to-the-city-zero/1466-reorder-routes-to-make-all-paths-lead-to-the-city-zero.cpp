class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int, int>>>& graph) {
        int changes = 0;
        for (auto [next, cost] : graph[node]) {
            if (next == parent){
                continue;
            }

            changes += cost;
            changes += dfs(next, node, graph);
        }
        return changes;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : connections) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back({b, 1});
            graph[b].push_back({a, 0});
        }
        return dfs(0, -1, graph);
    }
};