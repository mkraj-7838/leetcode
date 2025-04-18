class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string previous = countAndSay(n - 1);
        string result;
        int count = 1;
        for (int i = 0; i < previous.size(); ++i) {
            if (i + 1 < previous.size() && previous[i] == previous[i + 1]) {
                count++;
            } else {
                result += to_string(count) + previous[i];
                count = 1;
            }
        }
        return result;
    }
};