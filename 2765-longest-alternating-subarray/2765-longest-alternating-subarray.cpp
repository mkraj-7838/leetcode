class Solution {
public:
    int alternatingSubarray(vector<int> &arr) {
        int maxi=1,cnt=1;
        int prev;  
        int n=arr.size();
        for (int i=1;i<n;i++){
            if(cnt%2==1) prev=-1;
            else prev=1;
            if(prev==arr[i-1]-arr[i]) cnt++;
            else if(arr[i-1]-arr[i]==-1) cnt=2;
            else cnt=1;
            maxi=max(maxi,cnt);
        }       
        if(maxi==1) return -1;
        return maxi;     
    }
};
