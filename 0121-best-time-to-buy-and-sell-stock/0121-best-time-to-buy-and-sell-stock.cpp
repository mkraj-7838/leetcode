class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit=0, cost=0;

        for(int i=0; i<prices.size(); i++){
            cost=prices[i]-mini;
            maxProfit=max(maxProfit, cost);
            mini=min(mini, prices[i]);
        }
        return maxProfit;
    }
};