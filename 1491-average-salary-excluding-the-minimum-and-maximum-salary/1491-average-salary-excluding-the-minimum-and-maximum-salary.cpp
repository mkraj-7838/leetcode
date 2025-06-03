class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        double sum = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum = sum + salary[i];
            maxi=max(maxi, salary[i]);
            mini=min(mini, salary[i]);
        }
        double ans=(sum-maxi-mini)/(n-2);
        return ans;
    }
};