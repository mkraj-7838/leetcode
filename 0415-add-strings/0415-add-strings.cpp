class Solution {
public:
    string addStrings(string num1, string num2) {
        string res= "";
        int carry =0;
        int l1=num1.size()-1;
        int l2=num2.size()-1;
        while(l1>=0||l2>=0||carry)   
        {
            int d1 = (l1>=0)?num1[l1]-'0':0;
            int d2 = (l2>=0)?num2[l2]-'0':0;
            int sum = d1+d2+carry;
            carry= sum/10;
            res +=(sum%10)+'0';
            l1--;
            l2--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};