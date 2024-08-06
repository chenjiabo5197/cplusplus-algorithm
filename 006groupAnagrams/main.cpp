#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> str_vector;
        for (const auto& str : strs)
        {
            string temp  = str;
            std::sort(temp.begin(), temp.end());
            vector<string>::iterator it = std::find(str_vector.begin(), str_vector.end(), temp);
            if(it != str_vector.end())
            {
                // 在str_vector中包含该元素
                // 获取下标
                auto index = std::distance(str_vector.begin(), it);
                result[index].push_back(str);
            }
            else
            {
                // 在str_vector中不包含该元素
                vector<string> temp_vector;
                temp_vector.push_back(str);
                result.push_back(temp_vector);
                str_vector.push_back(temp);
            }
        }
        return result;
    }
};