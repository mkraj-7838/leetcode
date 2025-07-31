class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i = 0; i<n; i++){

            int currOR = arr[i];
            int prevOR = 0;
            int j = i-1;
            st.insert(currOR);

            // Check for previous number if they also same as curr means we found duplicate
            // So, just stop there
            while(j >= 0 && currOR != prevOR){
                currOR |= arr[j];
                prevOR |= arr[j];
                j--;
                st.insert(currOR);
            }
        }
        return st.size();
    }
};