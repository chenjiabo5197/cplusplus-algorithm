#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 栈中储存上面栈中温度的索引值
        stack<int> indexStack;
        vector<int> result(temperatures.size(), 0);
        for (int i = temperatures.size()-1; i >=0 ; --i) {
            while (!indexStack.empty() && temperatures[i] >= temperatures[indexStack.top()])
            {
                // 要找出一个大于当天温度的温度
                indexStack.pop();
            }
            if (!indexStack.empty())
            {
                // 若栈为空，则没有比当前温度值更高的天了
                result[i] = indexStack.top() - i;
            }
            // 将所有温度值推入栈中
            indexStack.push(i);
        }
        return result;
    }
};

int main()
{
    Solution sl;
    vector<int> v= {73,74,75,71,69,72,76,73};

    auto result = sl.dailyTemperatures(v);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}

