class Solution {
public:
    int minimumChairs(string s) {
        int len = 0;
        int maxl = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E') {
                len++;
                maxl = max(maxl, len);
            } else
                len--;
        }
        return maxl;
    }
};