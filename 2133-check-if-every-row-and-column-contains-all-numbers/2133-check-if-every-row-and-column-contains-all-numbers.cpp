class Solution {
public:
    bool checkValid(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // row check
        for (int i = 0; i < n; i++) {
            unordered_map<int, bool> map_R;

            for (int num : board[i]) {
                if (map_R[num]) { 
                    return false;
                }
                map_R[num] = true;
            }
            return true;
        }

        // col check
        for (int i = 0; i < m; i++) {
            unordered_map<int, bool> map_C;
            for (int num : board[i]) {
                if (map_C[num]) { 
                    return false;
                }
                map_C[num] = true;
            }
            return true;
        }

        return false;
    }
};