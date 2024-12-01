#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;
        for (int i = 0; i < s.length(); ++i) {
            char chS = s[i];
            auto itS = mapS.find(chS);
            char chT = t[i];
            auto itT = mapT.find(chT);
            if ((itS != mapS.end() && itS->second != chT) || (itT != mapT.end() && itT->second != chS))
            {
                return false;
            }
            else
            {
                mapS[chS] = chT;
                mapT[chT] = chS;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
//    vector<int> v = {1,2,3,1,2,3};
    auto result = s.isIsomorphic("badc", "baba");
    std::cout << result << std::endl;
//    for (int i = 0; i < result.size(); ++i) {
//        std::cout << result[i] << std::endl;
//    }
    return 0;
}

