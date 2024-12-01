#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> myStack;
        int result = 0;
        // 操作符号的表示，默认操作符号均为正数，若为负数，则置为-1
        int operatorSymbal = 1;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(ch >= '0' && ch <= '9')
            {
                long value = ch - '0';
                int index = i;
                while (++index < s.length() && (s[index]>= '0' && s[index]<='9'))
                {
                    // i++必须在前，因为value这时候取值应该去吧index后面的值了
                    i++;
                    value = (value * 10) + (s[i] - '0');
                }
                result = result + operatorSymbal * value;
            }
            else if(ch == '-')
            {
                operatorSymbal = -1;
            }
            else if(ch == '+')
            {
                operatorSymbal = 1;
            }
            else if(ch == '(')
            {
                // 符号操作符在数字上面
                myStack.push(result);
                myStack.push(operatorSymbal);
                operatorSymbal = 1;
                result = 0;
            }
            else if(ch == ')')
            {
                operatorSymbal = myStack.top();
                myStack.pop();
                int value = myStack.top();
                myStack.pop();
                result = value + result * operatorSymbal;
            }
        }
        return result;
    }
};

int main()
{
    Solution sl;

    auto result = sl.calculate("2147483647");
    std::cout << result << std::endl;
    return 0;
}

