class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int length = nums.size();
        vector<int> preSum(length+1, 0);
        for (int i = 1; i < preSum.size(); ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        for (int i = 1; i < preSum.size(); ++i) {
            if (preSum[i-1] == preSum[length]-preSum[i])
            {
                return i-1;
            }
        }
        return -1;
    }
};