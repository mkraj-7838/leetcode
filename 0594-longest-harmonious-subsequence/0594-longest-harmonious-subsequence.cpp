class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num:nums) mpp[num]++;
        int result=0;
        for(int num:nums){
            int minNum=num;
            int maxNum=num+1;
            if(mpp.find(maxNum)!=mpp.end()){
                result=(mpp[num]+mpp[num+1]);
            }
        }
        return result;
    }
};