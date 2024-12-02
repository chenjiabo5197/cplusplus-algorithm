class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // vector<int> preSum(nums.size() + 1, 0);
        // for (int i = 1; i < preSum.size(); ++i) {
        //     preSum[i] = preSum[i-1] + nums[i-1];
        // }
        // int ans = 0;
        // // 遍历所有子数组，从间隔1到间隔nums.size()
        // for (int i = 1; i <= nums.size(); ++i) {
        //     for (int j = 1; j < preSum.size(); ++j) {
        //         if(j-i >= 0 && preSum[j] - preSum[j-i] == k)
        //         {
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        // 记录以当前key为前缀和出现的次数
        unordered_map<int, int> preSumNums;
        // 前缀和数组
        vector<int> preSum(nums.size()+1, 0);
        int ans = 0;
        preSumNums[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            preSum[i+1] = preSum[i]+nums[i];
            // 注意：应该先在map中寻找有符合的前缀和没有，然后再将此时的前缀和添加到map中
            auto it = preSumNums.find( preSum[i+1] - k);
            if (it != preSumNums.end())
            {
                ans += it->second;
            }
            it = preSumNums.find(preSum[i+1]);
            if (it != preSumNums.end())
            {
                it->second++;
            }
            else
            {
                preSumNums[preSum[i+1]] = 1;
            }
        }
        return ans;
    }
};