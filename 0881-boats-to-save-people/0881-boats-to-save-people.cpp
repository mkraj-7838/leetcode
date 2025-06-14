class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        int left = 0;
        sort(people.begin() , people.end());
        int right = people.size()-1;
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                boats++;
                left++;
                right--;
            }
            else{
                boats++;
                right--;
            }
        }
        return boats;
    }
};