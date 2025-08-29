class Solution {
public:
    int findLengthOfLCIS(vector<int>& s) {
        int len = 1;
        int maxl = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] > s[i - 1]) {
                len++;
                maxl = max(maxl, len);
            } else
                len = 1;
        }
        return maxl;
    }
};