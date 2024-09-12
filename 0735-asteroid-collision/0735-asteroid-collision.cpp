class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> stk;
        for(int i=0; i<ast.size(); i++){
            if(ast[i]>0) stk.push(ast[i]);
            else{
                while(!stk.empty() && stk.top()>0 && stk.top()<abs(ast[i])){
                    stk.pop();
                }
                if(!stk.empty() && stk.top()==abs(ast[i])){
                    stk.pop();
                }else if(stk.empty() || stk.top()<0){
                    stk.push(ast[i]);
                }
            }
        }
        vector<int> res(stk.size());
        int i = stk.size() - 1;

        while (!stk.empty()) {
            res[i--] = stk.top();
            stk.pop();
        }
        return res; 
    }
};