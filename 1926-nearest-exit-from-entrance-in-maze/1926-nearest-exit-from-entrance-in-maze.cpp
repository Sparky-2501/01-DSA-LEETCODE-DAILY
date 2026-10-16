class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        int sr = entrance[0];
        int sc = entrance[1];
        q.push({{sr, sc}, 0});

        maze[sr][sc] = '+';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dist = curr.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // boundaries check for the grid.
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                if (maze[nr][nc] == '+') {
                    continue;
                }

                if (nr == 0 || nr == m - 1 ||
                    nc == 0 || nc == n - 1) {
                    return dist + 1;
                }

                maze[nr][nc] = '+';
                q.push({{nr, nc}, dist + 1});
            }
        }
        return -1;
    }
};