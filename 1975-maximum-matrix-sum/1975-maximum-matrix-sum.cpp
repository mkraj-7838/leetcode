class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum=0;
        int cntNeg=0;
        int absSmallest=INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    cntNeg++;
                }
                absSmallest=min(absSmallest, abs(matrix[i][j]));
            }
        }
        if(cntNeg%2==0){
            return sum;
        }
        return sum-2*absSmallest;
    }
};