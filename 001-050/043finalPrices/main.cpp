#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
//        for (int i = 0; i < prices.size(); ++i) {
//            for (int j = i+1; j < prices.size(); ++j) {
//                if(prices[j] <= prices[i])
//                {
//                    prices[i] -= prices[j];
//                    break;
//                }
//            }
//        }
//        return prices;
        // 栈中的元素是一个递增的序列
        stack<int> myStack;
        vector<int> result(prices.size(), 0);
        for (int i = prices.size()-1; i >=0 ; --i) {
            while (!myStack.empty() && prices[i] < myStack.top())
            {
                myStack.pop();
            }
            if (myStack.empty())
            {
                result[i] = prices[i];
            }
            else
            {
                result[i] = prices[i] - myStack.top();
            }
            myStack.push(prices[i]);
        }
        return result;
    }
};

int main()
{
    Solution sl;
    vector<int> v= {8,4,6,2,3};

    auto result = sl.finalPrices(v);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}

