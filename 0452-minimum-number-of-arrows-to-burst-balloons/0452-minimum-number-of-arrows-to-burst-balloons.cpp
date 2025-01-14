class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();

        sort(points.begin(), points.end());
        int count=1;
        vector<int> prev=points[0];

        for(int i=1; i<n; i++){

            if(points[i][0] > prev[1]){
                count++;
                prev=points[i];
            }
            else{
                prev[0]=max(points[i][0], prev[0]);
                prev[1]=min(points[i][1], prev[1]);
            }
        }
        return count;
    }
};