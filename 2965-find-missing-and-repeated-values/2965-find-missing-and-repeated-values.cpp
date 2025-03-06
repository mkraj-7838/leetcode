class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> ans(n*n+1, 0);
        int repeated=-1;
        int missing=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j++){
                if(ans[grid[i][j]]==1){
                    repeated=grid[i][j];
                }
                if(ans[grid[i][j]]==0){
                    ans[grid[i][j]]=1;
                }
            }
        }
        for(int i=1; i<=n*n; i++){
            if(ans[i]==0){
                missing=i;
            }
        }
        return {repeated, missing};
    }
};

