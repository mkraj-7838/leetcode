class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();

        int primary_sum = 0;
        int secondary_sum = 0;

        for (int i = 0; i < m; i++) {
            primary_sum += mat[i][i];
            secondary_sum += mat[i][m - i - 1];
        }

        if (m % 2 != 0) {
            primary_sum -= mat[m / 2][m / 2];
        }

        return primary_sum + secondary_sum;
    }
};