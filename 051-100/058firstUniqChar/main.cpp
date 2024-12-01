#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(s.length(), 0);
        unordered_map<char, int> charIndexMap;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            auto it = charIndexMap.find(ch);
            if (it != charIndexMap.end())
            {
                v[it->second]++;
                v[i]++;
            }
            else
            {
                charIndexMap[ch] = i;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
//    vector<int> v = {1,2,3,1,2,3};
    auto result = s.firstUniqChar("aabb");
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

