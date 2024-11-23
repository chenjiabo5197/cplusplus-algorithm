#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //    int majorityElement(vector<int>& nums) {
//        map<int, int> m;
//        for(int i=0;i<nums.size();i++)
//        {
//            auto it = m.find(nums[i]);
//            if(it == m.end())
//            {
//                m[nums[i]] = 1;
//            }
//            else
//            {
//                m[nums[i]] += 1;
//            }
//            if(m[nums[i]] > nums.size()/2)
//            {
//                return nums[i];
//            }
//        }
//        return -1;
//    }
//    int majorityElement(vector<int>& nums) {
//        map<int, int> m;
//        set<int> s;
//        for(int i=0;i<nums.size();i++)
//        {
//            int old_length = s.size();
//            s.insert(nums[i]);
//            if(old_length == s.size())
//            {
//                m[nums[i]] += 1;
//            }
//            else
//            {
//                m[nums[i]] = 1;
//            }
//            if(m[nums[i]] > nums.size()/2)
//            {
//                return nums[i];
//            }
//        }
//        return -1;
//    }
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int vote = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(vote == 0)
            {
                result = nums[i];
                vote++;
                continue;
            }
            if(nums[i] == result)
            {
                vote++;
            }
            else
            {
                vote--;
            }
        }
        return result;
    }
};

int main()
{
    Solution sl;
    vector<int> v = {2,2,1,1,1,2,2};

    auto result = sl.majorityElement(v);
    std::cout << result << std::endl;
    return 0;
}

