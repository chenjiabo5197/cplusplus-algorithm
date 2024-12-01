#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mySet;
        for (int i = 0; i < nums.size(); ++i) {
            if(!mySet.insert(nums[i]).second)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,1};
    auto result = s.containsDuplicate(v);
    std::cout << result << std::endl;
    return 0;
}

