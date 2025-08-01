class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        unordered_map<char, int> mpp;

        int i = 0, j = 0;

        while (j < s.size()) {
            mpp[s[j]]++;

            if (mpp.size() == j - i + 1) {
                mx = max(mx, j - i + 1);
            } else if (mpp.size() < j - i + 1) {
                while (mpp.size() < j - i + 1) {
                    mpp[s[i]]--;
                    if (mpp[s[i]] == 0)
                        mpp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};