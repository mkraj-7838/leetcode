class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int rem = s.size() % k;
        if (rem != 0) {
            int toAdd = k - rem;
            s.append(toAdd, fill); // Append 'fill' to make length multiple of k
        }

        vector<string> ans;
        for (int i = 0; i < s.size(); i += k) {
            ans.push_back(s.substr(i, k)); // Take substring of length k
        }

        return ans;
    }
};