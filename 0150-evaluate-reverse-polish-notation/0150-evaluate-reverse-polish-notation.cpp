class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; // Use stack<int> to store integers
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Perform the operation
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                // Convert string to integer and push onto the stack
                st.push(stoi(token));
            }
        }
        // The result is the last remaining element in the stack
        return st.top();
    }
};