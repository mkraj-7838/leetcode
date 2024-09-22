class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> dist(nums.begin(), nums.end());
        int distN=dist.size();

        unordered_map<int, int> freq;
        int count = 0, left = 0;

        for(int right=0; right<n; right++){
            freq[nums[right]]++;
            while(freq.size()== distN){
                count+=(n-right);
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
        } 
        return count;           
    }
};