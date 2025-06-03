class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& pt) {
        int x0 = pt[0][0], y0 = pt[0][1];
        int x1 = pt[1][0], y1 = pt[1][1];

        for (int i = 2; i < pt.size(); i++) {
            int x = pt[i][0], y = pt[i][1];
            if ((x1 - x0)*(y - y0) != (y1 - y0)*(x - x0))
                return false;
        }
        return true;
    }
};
