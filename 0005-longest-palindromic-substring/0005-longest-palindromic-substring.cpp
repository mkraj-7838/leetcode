class Solution {
public:
    bool isPalin(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxi = 0;
        int length = 0;
        int sp = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalin(s, i, j)) {
                    length = j - i + 1;
                    if (length > maxi) {
                        maxi = length;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxi);
    }
};