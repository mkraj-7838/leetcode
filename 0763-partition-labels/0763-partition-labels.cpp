class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hash;
        for(int i=0; i<s.size(); i++) {
            hash[s[i]] = i;
        }

        vector<int> res;
        int l = -1, r = 0;
        int size = hash[s[0]];

        while(r <= size) {
            size = max(size, hash[s[r]]);

            if(r == size) {
                res.push_back(size-l);
                if(r < s.size()) {
                    l = r;
                    r++;
                    size = hash[s[r]];
                    r--;
                }
            }
            r++;

        }
        return res;
    }
};