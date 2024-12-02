#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // 储存数组中元素出现的次数、第一次出现的位置、最后一次出现的位置
        unordered_map<int, vector<int>> valueInfo;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = valueInfo.find(nums[i]);
            if (it != valueInfo.end())
            {
                // 更新出现次数、最后一次出现的位置
                valueInfo[nums[i]][0]++;
                valueInfo[nums[i]][2] = i;
            }
            else
            {
                // 记录元素出现的次数、第一次出现的位置，最后一次出现的位置
                vector<int> temp = {1, i, i};
                valueInfo[nums[i]] = temp;
            }
        }
        int degree = 0;
        int ans = nums.size();
        for (auto it: valueInfo) {
            if (it.second[0] > degree)
            {
                ans = it.second[2] - it.second[1] + 1;
                degree = it.second[0];
            }
            else if(it.second[0] == degree)
            {
                ans = min(ans, it.second[2] - it.second[1] + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,2,3,1,4,2};
    auto result = s.findShortestSubArray(v);
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

