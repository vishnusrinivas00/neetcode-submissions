class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> freq;
        
        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = freq.top(); freq.pop();
                int b = freq.top(); freq.pop();
                
                if (token == "+") freq.push(b + a);
                else if (token == "-") freq.push(b - a);
                else if (token == "*") freq.push(b * a);
                else if (token == "/") freq.push(b / a);
            } else {
                freq.push(stoi(token));
            }
        }
        
        return freq.top();
    }
};
