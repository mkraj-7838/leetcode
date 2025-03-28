class Solution {
public:
    array<int, 4> di =  {-1, 1, 0, 0}, dj = {0, 0, -1, 1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<vector<int>>q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;
        int many = 0, qsz = q.size();
        vector<int> ans(qsz, 0);
        for (int i = 0; i < qsz; i++) {
            int val = q[i][0];
            many += advance(pq, val, grid);
            while (i < qsz && q[i][0] ==val) {
                ans[q[i][1]] = many;
                i++;
            }
            i--;
        }
        return ans;
    }
    int advance(priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>& pq, int val, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        while (!pq.empty() && pq.top()[0] < val) {
            auto t = pq.top();
            pq.pop();
            res++;
            for (int i = 0; i < 4; i++) {
                int ii = t[1] + di[i];
                int jj = t[2] + dj[i];
                if (!(ii >= 0 && ii < n && jj >= 0 && jj < m))
                    continue;
                if (grid[ii][jj] < 0) 
                    continue;
                pq.push({grid[ii][jj], ii, jj});
                grid[ii][jj] = -1;
            }
        }
        return res;
    } 
};