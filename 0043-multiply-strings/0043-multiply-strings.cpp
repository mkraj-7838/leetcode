class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        vector<int>v(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                int sum=((num1[i]-'0')*(num2[j]-'0'));
                sum+=v[i+j+1];
                v[i+j+1]=sum%10;
                v[i+j]+=sum/10;
            }
        }
        string s;
        for(auto u:v){
            if(!(s.empty()&&u==0)){
                s.push_back(u+'0');
            }
        }
        return s;
    }
};