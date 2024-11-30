class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 双指针，一个指针遍历数组，另一个指针指向要赋值元素的位置
        int replaceIndex = 1;
        int index = 1;
        while (index <= nums.size()-1)
        {
            // 刚开始的元素没有与其相同的元素
            if(index == 0)
            {
                index++;
                replaceIndex++;
            }
            if(nums[index] == nums[index-1])
            {
                // index指向的元素与前一个元素相同，则index向前移动，replaceIndex保持不同
                index++;
            }
            else
            {
                // 发现不同的元素后，将index指向的元素赋值给replaceIndex指向的元素，两者都+1
                nums[replaceIndex] = nums[index];
                replaceIndex++;
                index++;
            }
        }
        return replaceIndex;
    }
};