class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int> check(days + 2, 0);

        for (auto &m : meetings) {
            check[m[0]]++;      
            check[m[1] + 1]--;   
        }

        int occupied = 0, count = 0;
        for (int i = 1; i <= days; i++) {
            occupied += check[i]; 
            if (occupied == 0) count++; 
        }
        
        return count;
    }
};
