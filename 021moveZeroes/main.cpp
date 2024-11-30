class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 两个指针，一个指针遍历数组指向非0的数，一个指针指向要将非0数放置的位置
        int index = 0;
        int replaceIndex = 0;
        while (index <= nums.size()-1)
        {
            if(nums[index] == 0)
            {
                index++;
            }
            else
            {
                nums[replaceIndex] = nums[index];
                replaceIndex++;
                index++;
            }
        }
        // 将从replaceIndex往后的数都置为0，因为这些数都已经放到前面的数组中了，前面的0被覆盖了
        for (int i = replaceIndex; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};