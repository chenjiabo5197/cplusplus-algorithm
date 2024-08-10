#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        for (auto int_vec: intervals) {
            bool has_overlap = false;
//            int result_length = result.size();
            vector<int> temp;
            for (auto index = 0; index < result.size();) {
                if (int_vec[1] < result[index][0] || result[index][1] < int_vec[0])
                {
                    // 证明两者没有重合区间
                    index++;
                }
                else
                {
                    // 有重合区间，取最大值和最小值作为区间两端
                    has_overlap = true;
                    if(temp.size() == 2)
                    {
                        int min_value = std::min(std::min(int_vec[0], result[index][0]), temp[0]);
                        int max_value = std::max(std::max(int_vec[1], result[index][1]), temp[1]);
                        temp.clear();
                        temp.push_back(min_value);
                        temp.push_back(max_value);
                    }
                    else
                    {
                        temp.push_back(std::min(int_vec[0], result[index][0]));
                        temp.push_back(std::max(int_vec[1], result[index][1]));
                    }
                    result.erase(result.begin() + index);
                }
            }
            if(!has_overlap)
            {
                result.push_back(int_vec);
            }
            else
            {
                result.push_back(temp);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
//    std::vector<std::vector<int>> v;
//    std::vector<int> v1;
//    std::vector<int> v2;
//    std::vector<int> v3;
//    std::vector<int> v4;
//    std::vector<int> v5;
//    v1.push_back(2);
//    v1.push_back(3);
//    v2.push_back(4);
//    v2.push_back(5);
//    v3.push_back(6);
//    v3.push_back(7);
//    v4.push_back(8);
//    v4.push_back(9);
//    v5.push_back(1);
//    v5.push_back(10);
//    v.push_back(v1);
//    v.push_back(v2);
//    v.push_back(v3);
//    v.push_back(v4);
//    v.push_back(v5);
//    std::vector<std::vector<int>> v;
//    std::vector<int> v1;
//    std::vector<int> v2;
//    std::vector<int> v3;
//    std::vector<int> v4;
//    v1.push_back(1);
//    v1.push_back(3);
//    v2.push_back(2);
//    v2.push_back(6);
//    v3.push_back(8);
//    v3.push_back(10);
//    v4.push_back(15);
//    v4.push_back(18);
//    v.push_back(v1);
//    v.push_back(v2);
//    v.push_back(v3);
//    v.push_back(v4);
//    std::vector<std::vector<int>> v;
//    std::vector<int> v1;
//    std::vector<int> v2;
//    v1.push_back(1);
//    v1.push_back(4);
//    v2.push_back(1);
//    v2.push_back(4);
//    v.push_back(v1);
//    v.push_back(v2);
    std::vector<std::vector<int>> v;
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;
    std::vector<int> v5;
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back(5);
    v2.push_back(5);
    v3.push_back(2);
    v3.push_back(2);
    v4.push_back(3);
    v4.push_back(4);
    v5.push_back(3);
    v5.push_back(4);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    auto result= s.merge(v);
    for (auto & str_vec : result) {
        for (auto & it : str_vec) {
            std::cout << it << std::endl;
        }
        std::cout << "------------" << std::endl;
    }
}

