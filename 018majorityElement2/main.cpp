#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int result1 = nums[0];
        int result2 = nums[0];
        int vote1 = 0;
        int vote2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == result1)
            {
                vote1 ++;
                continue;
            }
            if(nums[i] == result2)
            {
                vote2 ++;
                continue;
            }
            if(vote1 == 0)
            {
                result1 = nums[i];
                vote1 = 1;
                continue;
            }
            if (vote2 == 0)
            {
                result2 = nums[i];
                vote2 = 1;
                continue;
            }
            vote1--;
            vote2--;
        }
        vote1 = 0;
        vote2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(result1 == nums[i])
            {
                vote1++;
            }
            else if(result2 == nums[i])
            {
                vote2++;
            }
        }
        if(vote1 > nums.size() / 3)
        {
            v.push_back(result1);
        }
        if(vote2 > nums.size() / 3)
        {
            v.push_back(result2);
        }
        return v;
    }
};

int main()
{
    Solution sl;
    vector<int> v = {3,2,3};

    auto result = sl.majorityElement(v);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}

