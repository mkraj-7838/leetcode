class Solution {
public:
    bool isThree(int n) {
        vector<int> nums;
        for(int i=1; i<=n; i++){
            if(n%i==0) nums.push_back(i); 
        }
        int size=nums.size();
        if(size==3) return true;
        else return false;
    }
};