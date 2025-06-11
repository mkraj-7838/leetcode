class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        int size=bookings.size();

        for(int i=0; i<size; i++){
            int start = bookings[i][0];
            int end = bookings[i][1];
            int seats = bookings[i][2];

            for (int j = start - 1; j < end; j++) {
                ans[j] += seats;
            }
        }
        return ans;
    }
};