class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>element;
        for( int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int right_op = element.top();
                element.pop();
                int left_op = element.top();
                element.pop();
                int res = left_op + right_op;
                element.push(res);
            }
            else if(tokens[i] == "-"){
                int right_op = element.top();
                element.pop();
                int left_op = element.top();
                element.pop();
                int res = left_op - right_op;
                element.push(res);
            }
            else if(tokens[i]== "*"){
                int right_op = element.top();
                element.pop();
                int left_op = element.top();
                element.pop();
                int res = left_op * right_op;
                element.push(res);
            }
            else if(tokens[i] == "/"){
                int right_op = element.top();
                element.pop();
                int left_op = element.top();
                element.pop();
                int res = left_op / right_op;
                element.push(res);
            }
            else{
            element.push(stoi(tokens[i]));
            }
        }
        return element.top();
    }
};
