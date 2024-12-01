#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.length()+1];
        // 此处初始化为false，默认都不能组成，因为下面循环会将false改为true，但是不会将true改为false，所以默认值为false
        // 此处不初始化leetcode编译不认为dp[j]是一个bool类型变量
        std::fill(dp, dp+s.length()+1, false);
        // 空字符串默认组成
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = i-1; j >= 0 ; --j) {
                // 状态转义方程dp[i]的状态由dp[j]和i-j决定，j为小于i的数，i-j的字符串在vector中则证明可以找到
                if(dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    // 递归，会超时
//    bool wordBreak(string s, vector<string>& wordDict) {
//        if(s == "")
//        {
//            return true;
//        }
//        for (int i = 0; i < wordDict.size(); ++i) {
//            if (s.substr(0, wordDict[i].length()) == wordDict[i] && wordBreak(s.substr(wordDict[i].length()), wordDict))
//            {
//                return true;
//            }
//        }
//        return false;
//    }
};

int main() {
    Solution s;
//    string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
//    std::vector<string> v = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string str = "leetcode";
    std::vector<string> v = {"leet", "code"};

    auto result= s.wordBreak(str, v);
    std::cout << result << std::endl;
}

