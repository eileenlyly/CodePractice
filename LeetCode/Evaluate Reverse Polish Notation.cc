class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i++){
            string x = tokens[i];
            if (x != "+" && x != "-" && x != "*" && x != "/") nums.push(stoi(x));
            else operation(x[0], nums);
        }
        return nums.top();
    }
    void operation(char op, stack<int> &n){
        int b = n.top();
        n.pop();
        int a = n.top();
        n.pop();
        int res;
        switch(op){
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
        }
        n.push(res);
    }
};