class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for (auto& x : arr)
            mp[x]++;
        for (auto it = mp.crbegin(); it != mp.crend(); ++it)
            if (it->first == it->second)
                return it->first;

        return -1;
    }
};