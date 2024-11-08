class Solution {
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, int newColor, int delR[], int delC[],
             int iniColor) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delR[i];
            int ncol = col + delC[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delR, delC, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, color, delR, delC, iniColor);
        return ans;
    }
};