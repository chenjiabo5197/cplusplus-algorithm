class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> sum = {0};
        for (int i = 1; i < arr.size()+1; ++i) {
            sum.push_back(sum[i-1] + arr[i-1]);
        }
        int ans = 0;
        // 寻找所有奇数长度的数组，1，3，5，。。。
        for (int i = 1; i <= arr.size(); i+=2) {
            for (int j = 0; j < arr.size(); ++j) {
                if (j+1-i >= 0)
                {
                    ans += sum[j+1] - sum[j+1-i];
                }
            }
        }
        return ans;
    }
};