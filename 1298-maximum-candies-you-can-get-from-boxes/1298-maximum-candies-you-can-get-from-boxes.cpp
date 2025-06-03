class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        unordered_set<int> closed;
        queue<int> q;
        int count = 0;

        for (int b : initialBoxes) {
            if (status[b] == 1) {
                q.push(b);
            } else {
                closed.insert(b);
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            count += candies[box];

            for (int key : keys[box]) {
                status[key] = 1;
            }

            for (int b : containedBoxes[box]) {
                closed.insert(b);
            }

            unordered_set<int> temp = closed;
            for (int b : temp) {
                if (status[b] == 1) {
                    q.push(b);
                    closed.erase(b);
                }
            }
        }

        return count;
    }
};
