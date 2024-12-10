class Solution {
public:
    int maximumLength(string s) {
        int minRange = 1, maxRange = s.size() - 2, length = -1;

        for (int i = minRange; i <= maxRange; i++) {
            unordered_map<string, int> record;

            for (int j = 0; j <= s.size() - i; j++) {
                string sub = s.substr(j, i);
                record[sub]++;
            }

            for (auto &entry : record) {
                if (entry.second >= 3) length = i;
            }
        }

        return length;
    }
};