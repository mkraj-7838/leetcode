class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.empty())
            return 1;
        vector<int> trustCount(n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            int truster = trust[i][0];
            int trustee = trust[i][1];
            trustCount[truster]--;
            trustCount[trustee]++;
        }
        for (int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};