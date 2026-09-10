class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int, int>> trash;
        int sr = -1, sc = -1;

        // Find start and all trash positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    trash.push_back({i, j});
                }
            }
        }

        int k = trash.size();

        // Map trash cell -> bit
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) {
            id[trash[i].first][trash[i].second] = i;
        }

        int fullMask = (1 << k) - 1;
        // dist[r][c][energy][mask]
        vector<vector<vector<vector<int>>>> dist(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    energy + 1,
                    vector<int>(1 << k, -1)
                )
            )
        );

        queue<array<int, 4>> q;

        dist[sr][sc][energy][0] = 0;
        q.push({sr, sc, energy, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c, e, mask] = q.front();
            q.pop();

            int moves = dist[r][c][e][mask];

            if (mask == fullMask)
                return moves;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                if (e == 0)
                    continue;   // Moving consumes 1 energy

                int ne = e - 1;
                int nmask = mask;

                if (classroom[nr][nc] == 'L') {
                    int bit = id[nr][nc];    // Collect trash
                    nmask |= (1 << bit);
                }

                if (classroom[nr][nc] == 'R') {
                    ne = energy;    // Recharge at 'R'
                }
                if (dist[nr][nc][ne][nmask] == -1) {
                    dist[nr][nc][ne][nmask] = moves + 1;
                    q.push({nr, nc, ne, nmask});
                }
            }
        }
        return -1;
    }
};