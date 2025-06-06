class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto& money: accounts){
            int sum=accumulate(money.begin(), money.end(),0);
            ans=max(ans, sum);
        }
        return ans;
    }
};