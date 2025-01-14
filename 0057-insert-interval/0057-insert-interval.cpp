class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> arr;
        bool inserted = false;

        for (const auto& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                // Current interval ends before new interval starts
                arr.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                // Current interval starts after new interval ends
                if (!inserted) {
                    arr.push_back(newInterval);
                    inserted = true;
                }
                arr.push_back(interval);
            } else {
                // There is overlap, merge intervals
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        // Insert the new interval at the end if it hasn't been inserted yet
        if (!inserted) {
            arr.push_back(newInterval);
        }

        return arr;
    }
};