#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 记录26个英文字母出现的次数
        vector<int> table(26, 0);
        for (int i = 0; i < magazine.length(); ++i)
        {
            int index = magazine[i] - 'a';
            table[index]++;
        }
        for (int i = 0; i < ransomNote.length(); ++i)
        {
            int index = ransomNote[i] - 'a';
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
    auto result = s.canConstruct("aa", "aab");
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

