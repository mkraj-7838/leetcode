class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cur=0;
        int max = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==1){
                cur++;
                if(cur>=3){
                    return true;
                }
            }else{
                cur=0;
            }
           
        }
        return false;
    }
};