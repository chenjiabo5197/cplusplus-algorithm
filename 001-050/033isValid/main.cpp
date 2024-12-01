class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch == ')' && !myStack.empty() && myStack.top() == '(')
            {
                myStack.pop();
            }
            else if(ch == ']' && !myStack.empty() && myStack.top() == '[')
            {
                myStack.pop();
            }
            else if(ch == '}' && !myStack.empty() && myStack.top() == '{')
            {
                myStack.pop();
            }
            else
            {
                myStack.push(ch);
            }
        }
        return myStack.empty();
    }
};