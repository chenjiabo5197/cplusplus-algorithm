#include <iostream>
#include <vector>
#include <map>

// 加一个map，执行快

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            int sub_value = target - nums[i];
            if(m.count(sub_value))
            {
                return {m[sub_value], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution sl;
    vector<int> temp = {2, 7, 11, 15};
    auto result = sl.twoSum(temp, 9);
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}