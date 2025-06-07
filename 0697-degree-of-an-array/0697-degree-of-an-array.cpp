class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for (int i=0;i<nums.size();i++){mp[nums[i]].push_back(i);}
        int m=INT_MIN,x;
        vector<int>temp;
        for (auto &it:mp){temp=it.second;x=temp.size();m=max(m,x);}
        int mi=INT_MAX;
        for (auto &it:mp){temp=it.second;x=temp.size();
            if (m==x){mi=min(mi,(temp.back()-temp.front()+1));}
        }
        return mi;
    }
};