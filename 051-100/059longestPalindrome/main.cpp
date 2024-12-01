#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charNums;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            auto it = charNums.find(ch);
            if (it != charNums.end())
            {
                it->second++;
            }
            else
            {
                charNums[ch] = 1;
            }
        }
        for (auto it = charNums.begin(); it != charNums.end() ; ++it) {
            // 此处目的是为了取偶数，比如有5个'a'，回文串中这一步只能用到4个
            ans += it->second / 2 * 2;
        }
        if (ans < s.length())
        {
            ans += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
//    vector<int> v = {1,2,3,1,2,3};
    auto result = s.longestPalindrome("abccccdd");
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

