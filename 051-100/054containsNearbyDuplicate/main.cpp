#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = myMap.find(nums[i]);
            if (it != myMap.end() && i - it->second <= k)
            {
                return true;
            }
            else
            {
                // 更新map,因为这个值第一次放入的索引值离他最近的索引值也不满足，所以将索引值替换为新的索引，看看后面还有没有能和新索引匹配的
                myMap[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,1,2,3};
    auto result = s.containsNearbyDuplicate(v, 2);
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

