class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int size=nums.size();
        k=k%size;
        if (k == 0) return; 
        int temp[k];

        for(int i=size-k, j=0; i<size; i++, j++)
            temp[j]=nums[i];

        for(int i=size-k-1; i>=0; i--)
            nums[i+k]=nums[i];

        for(int i=0; i<k; i++)
            nums[i]=temp[i];
    }
};