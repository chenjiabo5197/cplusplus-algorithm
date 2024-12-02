class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 储存到索引位置奇数出现的次数，包含索引元素
        vector<int> oddNums(nums.size()+1, 0);
        // 记录出现奇数的次数
        unordered_map<int, int> oddNumMap;
        oddNumMap[0] = 1;
        int ans = 0;
        for (int i = 1; i < oddNums.size(); ++i) {
            if (nums[i-1] % 2 == 0)
            {
                oddNums[i] = oddNums[i-1];
            }
            else
            {
                oddNums[i] = oddNums[i-1] + 1;
            }
            auto it = oddNumMap.find(oddNums[i]);
            if (it != oddNumMap.end())
            {
                it->second++;
            }
            else
            {
                oddNumMap[oddNums[i]] = 1;
            }
            it = oddNumMap.find(oddNums[i] - k);
            if (it != oddNumMap.end())
            {
                ans += it->second;
            }
        }
        return ans;
    }
};