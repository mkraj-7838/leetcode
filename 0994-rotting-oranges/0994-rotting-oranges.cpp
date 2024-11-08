class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cntFresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    cntFresh++;
                else if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int maxtime = 0;
        int delx[] = {-1, 0, 1, 0};
        int dely[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            maxtime = max(maxtime, time);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = x + delx[i];
                int col = y + dely[i];
                if (row >= 0 && col >= 0 && row < n && col < m &&
                    vis[row][col] == 0 && grid[row][col] == 1) {
                    vis[row][col] = 2;
                    q.push({{row, col}, time + 1});
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return maxtime;
    }
};