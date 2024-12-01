#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // 栈中储存左括号的索引值，因为有可能出现(()，所以需要判断左边第几个括号可以跟右边的括号匹配成功的
        stack<int> myStack;
        int maxValid = 0;
        // 记录与当前右括号匹配的左括号的索引值
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch == '(')
            {
                myStack.push(i);
            }
            else
            {
                if(myStack.empty())
                {
                    start = i+1;  // 栈为空，则从i+1开始的符号才可能与后面的右括号匹配
                    // 记录此索引值，在栈为空的情况下证明有好几对（）匹配成功，用start可以获取到最初的左括号的索引值
                }
                else
                {
                    myStack.pop();
                    if(myStack.empty())
                    {
                        // 弹出栈顶元素后，此时栈为空，说明跟当前右括号匹配的左括号的索引为start
                        int maxLength = (i-start)+1;
                        maxValid = max(maxValid, maxLength);
                    }
                    else
                    {
                        // 弹出栈顶元素后，此时栈不为空，说明跟当前右括号匹配的左括号的索引为栈顶元素+1
                        int maxLength = (i-(myStack.top()+1)) + 1;
                        maxValid = max(maxValid, maxLength);
                    }
                }
            }
        }
        return maxValid;
    }
};

int main()
{
    Solution sl;

    auto result = sl.longestValidParentheses(")()())");
    std::cout << result << std::endl;
    return 0;
}

