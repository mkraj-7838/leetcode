class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_set<int> s;
        for (int num : candyType) {
            s.insert(num);  
        }
        int size=s.size();
        int ans=min(n/2, size);
        return ans;
    }

};