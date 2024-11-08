class Solution {
private:
    void dfs(int node, unordered_map<int, vector<int>>& adjLs,
             unordered_map<int, bool>& vis) {
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adjLs;
        int n = isConnected.size();
        int m = isConnected[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != j && isConnected[i][j]) {
                    adjLs[i].push_back(j);
                }
            }
        }

        int count = 0;
        unordered_map<int, bool> vis;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjLs, vis);
            }
        }

        return count;
    }
};