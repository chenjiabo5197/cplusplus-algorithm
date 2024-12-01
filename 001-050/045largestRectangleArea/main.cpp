#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
//    int largestRectangleArea(vector<int>& heights) {
//        int maxArea = 0;
//        // 新建一个数组，给heights数组的前后都+0，让heights数组的头、尾元素和其他元素处于同一地位
//        vector<int> newHeights(heights.size()+2, 0);
//        for (int i = 1; i < newHeights.size()-1; ++i) {
//            newHeights[i] = heights[i-1];
//        }
//        for (int i = 0; i < newHeights.size(); ++i) {
//            if (newHeights[i] == 0)
//            {
//                continue;
//            }
//            // 从头到尾遍历元素，招待以i为高度，左边最小的索引和右边最大的索引，从最小索引到最大索引处，每个索引处的值都大于等于i索引的值
//            int start = i;
//            int end = i;
//            for (int j=i-1; j >=0; --j) {
//                if (newHeights[j] < newHeights[i])
//                {
//                    break;
//                }
//                start = j;
//            }
//            for (int k=i+1; k < newHeights.size(); ++k) {
//                if(newHeights[k] < newHeights[i])
//                {
//                    break;
//                }
//                end = k;
//            }
//            // 所以以i为高度的最大矩形面积为
//            maxArea = max(maxArea, (end - start + 1) * newHeights[i]);
//        }
//        return maxArea;
//    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        // 新建一个数组，给heights数组的前后都+0，让heights数组的头、尾元素和其他元素处于同一地位
        vector<int> newHeights(heights.size() + 2, 0);
        for (int i = 1; i < newHeights.size() - 1; ++i) {
            newHeights[i] = heights[i - 1];
        }
        // 单调栈，储存newHeights的索引值，栈中索引值对应的值是递增的，从而可以做到在当前索引值时，栈中其上面索引对应的值都大于等于该值，
        // 下面索引的值都小于该索引值，从而该索引对应的最大面积为该索引值的（遍历的当前元素索引-栈中底下的索引）*该索引对应的值
        stack<int> myStack;
        for (int i = 0; i < newHeights.size(); ++i) {
            while (!myStack.empty() && newHeights[i] < newHeights[myStack.top()])
            {
                int curIndex = myStack.top();
                myStack.pop();
                // 弹出该值，证明以改索引值为高度的矩形最大的右边索引已经找到了
                int height = newHeights[curIndex];
                // 左边索引为当前栈顶元素，若栈顶元素与该索引值相等，则还可以继续获取栈顶元素的最大面积。当前栈顶元素的值不会比该索引值小
                int leftIndex = myStack.top();
                int rightIndex = i;
                // 此处-1是因为右侧索引值多算了1个
                int area = (rightIndex - leftIndex - 1) * height;
                maxArea = max(maxArea, area);
            }
            myStack.push(i);
        }
        return maxArea;
    }
};

int main()
{
    Solution sl;
    vector<int> v= {4,2,0,3,2,4,3,4};

    auto result = sl.largestRectangleArea(v);
    std::cout << result << std::endl;
    return 0;
}

