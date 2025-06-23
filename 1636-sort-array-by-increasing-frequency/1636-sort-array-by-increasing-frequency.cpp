class Solution {
public:
    
    typedef pair<int, int> ppi;
    struct comp {
        bool operator()(const ppi& a, const ppi& b) {
            if (a.first == b.first)
                return a.second < b.second; // larger element later
            return a.first > b.first;       // lower frequency first
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;

        priority_queue<ppi, vector<ppi>, comp> minH;

        for (auto& it : mp) {
            minH.push({it.second, it.first});
        }

        vector<int> ans;
        while (!minH.empty()) {
            int freq = minH.top().first;
            int ele = minH.top().second;
            minH.pop();
            while (freq--)
                ans.push_back(ele);
        }

        return ans;
    }
};