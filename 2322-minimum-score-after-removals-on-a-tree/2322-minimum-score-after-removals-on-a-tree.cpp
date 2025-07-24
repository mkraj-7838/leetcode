class Solution {
public:
    int totalXOR;  // Stores the XOR of the entire tree
    vector<vector<int>> tree;  // Adjacency list to represent the tree
    vector<int> xorSubtree;    // Stores XOR value of each node’s subtree
    vector<int> inTime, outTime;  // Used to check subtree relationships
    int timer;  // Global timer for DFS timestamps

    // DFS traversal to compute subtree XORs and assign timestamps
    void dfs(int node, int parent, const vector<int>& nums) {
        xorSubtree[node] = nums[node];  // Start with node's own value
        inTime[node] = ++timer;         // Entry time in DFS

        for (int child : tree[node]) {
            if (child == parent) continue;  // Skip parent to avoid revisiting
            dfs(child, node, nums);         // Recursive DFS on children
            xorSubtree[node] ^= xorSubtree[child];  // Accumulate XOR from subtree
        }

        outTime[node] = ++timer;  // Exit time in DFS
    }

    // Utility to check if node u is inside the subtree rooted at node v
    bool isDescendant(int u, int v) {
        return inTime[v] < inTime[u] && outTime[u] < outTime[v];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.resize(n); xorSubtree.resize(n);
        inTime.resize(n); outTime.resize(n);
        timer = 0;

        // Build the undirected tree (graph)
        for (const auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, -1, nums);  // Start DFS from root node 0
        totalXOR = xorSubtree[0];  // XOR of the entire tree

        int minScore = INT_MAX;

        // Try all pairs of nodes to simulate removing edges to form 3 parts
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Start with default assumption that edges are independent
                int xor1 = xorSubtree[i];
                int xor2 = xorSubtree[j];
                int xor3 = totalXOR;

                // If i lies inside j’s subtree
                if (isDescendant(i, j)) {
                    xor1 = xorSubtree[i];                      // Deep subtree
                    xor2 = xorSubtree[j] ^ xorSubtree[i];      // Remaining part of j's subtree
                    xor3 = totalXOR ^ xorSubtree[j];           // Rest of the tree
                }
                // If j lies inside i’s subtree
                else if (isDescendant(j, i)) {
                    xor1 = xorSubtree[j];                      // Deep subtree
                    xor2 = xorSubtree[i] ^ xorSubtree[j];      // Remaining part of i's subtree
                    xor3 = totalXOR ^ xorSubtree[i];           // Rest of the tree
                }
                // If they are in separate branches
                else {
                    xor3 = totalXOR ^ xorSubtree[i] ^ xorSubtree[j];
                }

                // Compute score and update minimum
                int maxX = max({xor1, xor2, xor3});
                int minX = min({xor1, xor2, xor3});
                minScore = min(minScore, maxX - minX);
            }
        }

        return minScore;
    }
};
