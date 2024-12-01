#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> mySet;
        for (int i = 0; i < nums1.size(); ++i) {
            mySet.insert(nums1[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums2.size(); ++i) {
            if(mySet.count(nums2[i]) == 1)
            {
                ans.push_back(nums2[i]);
                // 删除该元素，防止重复
                mySet.erase(nums2[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v1 = {4,7,9,7,6,7};
    vector<int> v2 = {5,0,0,6,1,6,2,2,4};
    auto result = s.intersection(v1, v2);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    return 0;
}

