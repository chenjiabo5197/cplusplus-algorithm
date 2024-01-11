#include <iostream>
#include <vector>

// 两次循环，占用内存少

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        int size = nums.size();
        for(int i = 0; i < size;i++)
        {
            for(int j=i+1; j<size;j++)
            {
                if(nums[i] + nums[j] == target){
                    temp.push_back(i);
                    temp.push_back(j);
                    return temp;
                }
            }
        }
        return temp;
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



