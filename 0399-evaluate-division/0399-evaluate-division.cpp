class Solution {
public:

unordered_map<string, vector<pair<string, double>>> graph;
  
    double dfs(string src, string dest, unordered_set<string>& visited) {
        if (!graph.count(src) || !graph.count(dest)){
            return -1.0;
        }

        if (src == dest){
            return 1.0;
        }

        visited.insert(src);
        for (auto& [next, weight] : graph[src]) {
            if (visited.count(next)){
                continue;
            }
            double result = dfs(next, dest, visited);
            if (result != -1.0)
                return weight * result;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }
        vector<double> ans;
        for (auto& q : queries) {
            unordered_set<string> visited;
            ans.push_back(dfs(q[0], q[1], visited));
        }
        return ans;
    }
};