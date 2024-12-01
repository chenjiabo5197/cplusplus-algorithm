class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNums = 0;
        int tempMaxNums = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1)
            {
                tempMaxNums++;
            }
            else
            {
                tempMaxNums = 0;
            }
            if (tempMaxNums > maxNums)
            {
                maxNums = tempMaxNums;
            }
        }
        return maxNums;
    }
};