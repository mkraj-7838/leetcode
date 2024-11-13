class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        // Create an adjacency list for the graph
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Initialize the in-degree array
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Initialize the queue with nodes having in-degree of 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform Kahn's algorithm for topological sorting
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce in-degree for all adjacent nodes
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the topological sort includes all nodes, return the order
        if (topo.size() == V) return topo;
        return {};
    }
};