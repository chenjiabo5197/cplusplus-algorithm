#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // cmp 接收两个 pair<int, int> 类型的参数 a 和 b，
        // 然后比较 nums1[a.first] + nums2[a.second] 和 nums1[b.first] + nums2[b.second] 的值。
        // 如果 a 对应的两个数组元素之和大于 b 对应的和，则返回 true，否则返回 false
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b)
        {
            return nums1[a.first]+nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        // decltype是一个操作符，它用于查询表达式的类型而不进行实际计算
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.emplace(0, i);
        }
        while (k>0)
        {
            k--;
            auto [x, y] = pq.top();
            pq.pop();
            vector<int> v = {nums1[x], nums2[y]};
            ans.push_back(v);
            if (x+1 < m)
            {
                pq.emplace(x+1, y);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {1,2,4,5,6};
    vector<int> v2 = {3,5,7,9};
    auto result = s.kSmallestPairs(v1, v2, 3);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << std::endl;
        }
        std::cout << "---------------" << std::endl;
    }
    return 0;
}

