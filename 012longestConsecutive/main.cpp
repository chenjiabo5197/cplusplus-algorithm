#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        std::sort(nums.begin(), nums.end());
        std::multimap<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(nums[i]-1);
            if(it != m.end())
            {
                m.insert(std::make_pair(nums[i], it->second+1));
                m.erase(it);
            }
            else
            {
                m.insert(std::make_pair(nums[i], 1));
            }
        }
        for(auto item: m)
        {
            if (item.second > result)
            {
                result  = item.second;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
//    std::vector<int> v = {0,3,7,2,5,8,4,6,0,1};
    std::vector<int> v = {0, 0, -1};

    auto result= s.longestConsecutive(v);
    std::cout << result << std::endl;
}

