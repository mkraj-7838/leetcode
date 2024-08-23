class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool letter=false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                count++;
                letter=true;
            }else if(letter){
                break;
            }
            
        }
        return count;
    }
};