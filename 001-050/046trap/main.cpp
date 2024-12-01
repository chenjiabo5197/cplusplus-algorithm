#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 单调递增栈
        stack<int> myStack;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            // 栈不为空且栈顶元素小于当前元素，则进入判断，看是否有洼地
            while (!myStack.empty() && height[myStack.top()] < height[i])
            {
                int top = height[myStack.top()];
                myStack.pop();
                // 栈顶元素弹出之后，栈为空，则证明无洼地
                if (myStack.empty())
                {
                    myStack.push(i);
                    break;
                }
                else
                {
                    // 此时有洼地，先获取两边高度的最小值，然后再减去弹出的先前栈顶元素的索引值，因为是以其为洼地的最低处的，得到洼地的高度
                    int minHeight = min(height[myStack.top()], height[i]);
                    int height = minHeight - top;
                    // 获取洼地的宽度
                    int width = i - myStack.top() - 1;
                    res += width * height;
                }
            }
            // 当前栈为空且栈顶元素的索引值大于等于当前遍历的索引值，直接入栈（有可能组成洼地），此判断必须放在if后面，
            // 因为要判断当前元素在进行前面的弹栈之后是否要进行入栈操作
            if (myStack.empty() || height[myStack.top()] >= height[i])
            {
                myStack.push(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution sl;
    vector<int> v= {4,2,0,3,2,5};

    auto result = sl.trap(v);
    std::cout << result << std::endl;
    return 0;
}

