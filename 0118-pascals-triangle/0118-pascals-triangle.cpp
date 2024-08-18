class Solution {
public:
    vector<int> generateRows(int row){
        vector<int> ans;
        ans.push_back(1);
        long long res=1;
        for(int col=1; col<row; col++ ){
            res=res*(row-col);
            res=res/col;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pT;
        for(int row=1; row<=numRows; row++){
            pT.push_back(generateRows(row));
        }
        return pT;
    }
};