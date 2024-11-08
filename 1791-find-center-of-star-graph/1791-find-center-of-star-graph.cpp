class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> connections(n+1, 0);
        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < 2; j++) {
                connections[edges[i][j]]++;
            }
        }
        for (int i = 1; i <= n ; i++) {
            if (connections[i] == n - 1)
                return i;
        }
        return -1;
    }
};
