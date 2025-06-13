class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> freq_num;
        for (auto elem : count) {
            freq_num.push_back({elem.second, elem.first});
        }

        sort(freq_num.begin(), freq_num.end());

        vector<int> top_k;
        for (int i = freq_num.size() - 1; i >= freq_num.size() - k && i >= 0; i--) {
            top_k.push_back(freq_num[i].second);
        }

        return top_k;
    }
};