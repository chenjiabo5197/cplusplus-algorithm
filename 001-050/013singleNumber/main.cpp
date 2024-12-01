#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; ) {
            if(nums[i] == nums[i+1])
            {
                i += 2;
            }
            else
            {
                return nums[i];
            }
        }
        return nums[nums.size()-1];
    }
};