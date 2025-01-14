class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
        intervals.push_back(newIntervals);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int size=intervals.size();

        for(int i=0; i<size; i++){
            if(ans.empty() || intervals[i][0]>ans.back()[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1]=max(ans.back()[1], intervals[i][1]);
        }
        return ans;
    }
};