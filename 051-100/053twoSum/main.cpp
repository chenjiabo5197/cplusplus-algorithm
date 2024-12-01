#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            int num = target - nums[i];
            auto it = myMap.find(num);
            if (it != myMap.end())
            {
                return {i, it->second};
            }
            else
            {
                myMap[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> v = {2,7,11,15};
    auto result = s.twoSum(v, 9);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}

