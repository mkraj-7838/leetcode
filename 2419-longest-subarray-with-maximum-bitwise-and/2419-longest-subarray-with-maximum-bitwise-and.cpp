class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0, len = 1;
        int cur = nums[0], last = nums[0];

        for(int i=1;i<nums.size();i++){
            if(cur == nums[i]){len++;}
            else{
                if(last < cur){
                    mx = len;
                    last = cur;
                }
                else if(last == cur){mx = max(mx, len);}

                len=1;
                cur=nums[i];
            }
        }

        if(last < cur){ mx = len; }
        else if(last == cur){mx = max(mx, len);}

        return mx;
    }
};