class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Row check
        for (int i = 0; i < m; i++) {
            unordered_map<char, bool> map_R;
            for (int j = 0; j < n; j++) {
                char num = board[i][j];
                if (num != '.') { // Ignore empty cells
                    if (map_R[num]) {
                        return false; // Duplicate in row
                    }
                    map_R[num] = true;
                }
            }
        }

        // Column check
        for (int j = 0; j < n; j++) {
            unordered_map<char, bool> map_C;
            for (int i = 0; i < m; i++) {
                char num = board[i][j];
                if (num != '.') { // Ignore empty cells
                    if (map_C[num]) {
                        return false; // Duplicate in column
                    }
                    map_C[num] = true;
                }
            }
        }

        // 3x3 sub-grid check
        for (int row = 0; row < m; row += 3) {
            for (int col = 0; col < n; col += 3) {
                unordered_map<char, bool> map_Grid;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char num = board[row + i][col + j];
                        if (num != '.') { // Ignore empty cells
                            if (map_Grid[num]) {
                                return false; // Duplicate in 3x3 grid
                            }
                            map_Grid[num] = true;
                        }
                    }
                }
            }
        }

        return true; // If all checks pass
    }
};