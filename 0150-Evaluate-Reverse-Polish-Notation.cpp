class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int a;
        int b;
        int c;
        
        for(const auto token: tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                if( token == "+")
                {
                  c = a + b;
                }
                else if( token == "-")
                {
                    c = a - b;
                }
                else if (token == "*")
                {
                   c = a * b;
                }
                else if( token == "/")
                {
                   c = a / b;
                }
                stack.push_back(c);
            } 
            else
            {
                stack.push_back(stoi(token));
            }  
        }
        return stack.back();
    }
};