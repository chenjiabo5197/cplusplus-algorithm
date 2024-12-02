class NumArray {
public:
    vector<int> sumNums;
    NumArray(vector<int>& nums) {
        sumNums.push_back(0);
        for (int i = 1; i < nums.size() + 1; ++i) {
            sumNums.push_back(sumNums[i-1] + nums[i-1]);
        }
    }

    int sumRange(int left, int right) {
        return sumNums[right+1] - sumNums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */