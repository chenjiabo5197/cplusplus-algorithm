#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int vector_length = nums.size();
        // 记录从后向前最大的值
        int max_index = vector_length-1;
        for (int i = vector_length-1; i >=0 ; --i)
        {
            if(nums[i] > nums[max_index])
            {
                max_index = i;
            }
            else if(nums[i] < nums[max_index])
            {
                // 出现比后面最大值小的数，需要再次遍历后面的数，找到比nums[i]大，但是在后面是最小的
                int min_index = i+1;
                for (int j= i+1; j <= vector_length-1; ++j) {
                    if (nums[j] > nums[i] && nums[j] < nums[min_index])
                    {
                        min_index = j;
                    }
                }
                int temp = nums[i];
                nums[i] = nums[min_index];
                nums[min_index] = temp;
                // 从i+1往后需要是顺排的
                std::sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        // 数据是一个逆序排列的，需要顺序重排一下
        std::sort(nums.begin(), nums.end());
    }
};