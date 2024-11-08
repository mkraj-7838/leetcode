class Solution {
public:
    bool dfs(int node, int destn, vector<vector<int>>& adjList, vector<bool>& visited) {
        if (node == destn) return true;

        visited[node] = true;

        for (int it : adjList[node]) {
            if (!visited[it]) {
                if (dfs(it, destn, adjList, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int destn) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(src, destn, adjList, visited);
    }
};