#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        ll jump=0, num=k;

        while(num > 1){
            ll lo_range = log2(num);
            ll hi_range = lo_range + 1;

            ll border = (1ll<<lo_range);

            if(border == num){
                lo_range--;
                border = (1ll<<lo_range);
            }

            int ind = lo_range; // or hi_range - 1
            
            num -= border;            

            if(operations[ind] == 1){jump++;}
        }

        return (char)('a' + jump%26);
    }
};