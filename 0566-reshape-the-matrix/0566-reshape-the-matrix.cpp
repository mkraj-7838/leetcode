class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row= mat.size();
        int col = mat[0].size();
        if( row *col != r*c)
            return mat;
        int p =0 , q=0;
        vector < vector <int >> arr( r, vector<int>(c) );
        for( int i = 0 ; i < row ;i++){
            for  ( int  j= 0 ; j  <col ; j++)
            {
                arr[p/c][q%c] = mat[i][j];
                p++;
                q++;
            }
        }
        return arr;
    }
};