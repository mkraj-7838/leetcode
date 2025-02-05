class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end());
        vector<int> current=intervals[0];

        for (int i = 1; i < intervals.size(); i++) {

            if (current[1] >= intervals[i][0]) {
                current[1]=max(current[1], intervals[i][1]);

            } else {
                ans.push_back(current);
                current=intervals[i];
            }
        }
        ans.push_back(current);
        return ans;
    }
};