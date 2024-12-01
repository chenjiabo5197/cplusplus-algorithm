class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for(int i=0;i<tokens.size();i++)
        {
            string temp = tokens[i];
            if(temp == "+" || temp == "-" || temp == "*" || temp == "/")
            {
                int temp1 = myStack.top();
                myStack.pop();
                int temp2 = myStack.top();
                myStack.pop();
                int result = -1;
                if(temp == "+")
                {
                    result = temp2+temp1;
                }
                else if(temp == "-")
                {
                    result = temp2-temp1;
                }
                else if(temp == "*")
                {
                    result = temp2*temp1;
                }
                else
                {
                    result = temp2/temp1;
                }
                myStack.push(result);
            }
            else
            {
                myStack.push(std::stoi(temp));
            }
        }
        return myStack.top();
    }
};