class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        map<float, int> mp;
        vector<string> st;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (mp.find(float(i) / j) != mp.end()) {
                    continue;
                } else {
                    mp[float(i) / j] = 1;
                    st.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return st;
    }
};