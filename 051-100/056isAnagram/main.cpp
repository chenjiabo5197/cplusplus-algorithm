#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
//        if (s.length() != t.length())
//        {
//            return false;
//        }
//        unordered_map<char, int> mapS;
//        unordered_map<char, int> mapT;
//        for (int i = 0; i < s.length(); ++i) {
//            char chS = s[i];
//            char chT = t[i];
//            auto it = mapS.find(chS);
//            if (it != mapS.end())
//            {
//                it->second += 1;
//            }
//            else
//            {
//                mapS[chS] = 1;
//            }
//            auto it2 = mapT.find(chT);
//            if (it2 != mapT.end())
//            {
//                it2->second += 1;
//            }
//            else
//            {
//                mapT[chT] = 1;
//            }
//        }
//        if (mapS.size() != mapT.size())
//        {
//            return false;
//        }
//        for (auto it = mapS.begin(); it != mapS.end(); ++it) {
//            auto it2 = mapT.find(it->first);
//            if (it2 == mapT.end() || it->second != it2->second)
//            {
//                return false;
//            }
//        }
//        return true;
        if (s.length() != t.length())
        {
            return false;
        }
        // 记录26个英文字母出现的次数
        vector<int> table(26, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            int index = s[i] - 'a';
            table[index]++;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            int index = t[i] - 'a';
            table[index]--;
            if (table[index] < 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
//    vector<int> v = {1,2,3,1,2,3};
    auto result = s.isAnagram("rat", "car");
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

