class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int rem = n % k;
        if (rem != 0) {
            int count = k - rem;  // characters to add
            for (int i = 0; i < count; i++) {
                s.push_back(fill);
            }
        }
        vector<string> ans;
        for (int i = 0; i < s.size(); i + k) {
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};