class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        int x = INT_MIN, y = INT_MAX;

        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if(freq[i] == 0)
            continue;

            if(freq[i] % 2 == 1)
                x = max(x, freq[i]);
            else
                y = min(y, freq[i]);
        }

        return (x - y);
    }
};