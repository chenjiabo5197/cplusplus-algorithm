class Solution {
public:
    int maxDepth(string s) {
        stack<char> myStack;
        int maxDepth = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch == '(')
            {
                myStack.push(ch);
            }
            else if (ch == ')')
            {
                int temp = myStack.size();
                if(temp > maxDepth)
                {
                    maxDepth = temp;
                }
                myStack.pop();
            }
        }
        return maxDepth;
    }
};