class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // index用于遍历数组，找到与val不相等的数，replaceIndex是指向与val相等的数
        int index = 0;
        int replaceIndex = 0;
        // 注：此处不能使用index <= nums.size()-1，因为-1后是一个很大的数
        // 因为nums.size()返回的是一个无符号整数类型，0-1会产生下溢，结果是一个很大的正数
        while (index < nums.size())
        {
            if(nums[index] != val)
            {
                nums[replaceIndex] = nums[index];
                index++;
                replaceIndex++;
            }
            else
            {
                index++;
            }
        }
        return replaceIndex;
    }
};