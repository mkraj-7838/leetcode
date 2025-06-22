class Solution {
public:
    string minWindow(string s, string t) {
        // base condition
        if (s.length() < t.length()) return "";
        unordered_map<char, int> mp;
        for (char &c: t) mp[c]++;

        int i = 0, j = 0, start = 0, ans = INT_MAX, count = mp.size();

        while (j < s.length()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0) {
                count--;
            }
            // try minimize the window size
            if (count == 0) {
                while (count == 0) {
                    if (ans > j - i + 1) {
                        ans = j - i + 1;
                        // update the ans
                        start = i;
                    }
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if (mp[s[i]] > 0) {
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if (ans != INT_MAX) {
            return s.substr(start, ans);
        }
        return "";
    }
};