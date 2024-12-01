#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<std::vector<int>> isUse(board.size(), std::vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == word[0])
                {
                    isUse[i][j] = 1;
                    if(existWholeWord(board, isUse, i-1, j, 1, word) || existWholeWord(board, isUse, i+1, j, 1, word) || existWholeWord(board, isUse, i, j+1, 1, word) || existWholeWord(board, isUse, i, j-1, 1, word))
                    {
                        return true;
                    }
                    else
                    {
                        isUse[i][j] = 0;
                    }
                }
            }
        }
        return false;
    }

    bool existWholeWord(vector<vector<char>>& board, vector<vector<int>>& isUse, int i, int j, int index, string wholeWord)
    {
        if (index >= wholeWord.size())
        {
            return true;
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
            return false;
        }
        if(isUse[i][j] == 0 && board[i][j] == wholeWord[index])
        {
            isUse[i][j] = 1;
            if(existWholeWord(board, isUse, i-1, j, index+1, wholeWord) || existWholeWord(board, isUse, i+1, j, index+1, wholeWord) || existWholeWord(board, isUse, i, j+1, index+1, wholeWord) || existWholeWord(board, isUse, i, j-1, index+1, wholeWord))
            {
                return true;
            }
            else
            {
                isUse[i][j] = 0;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> v;
    std::vector<char> v1;
    std::vector<char> v2;
    std::vector<char> v3;
    v1.push_back('A');
    v1.push_back('B');
    v1.push_back('C');
    v1.push_back('E');
    v2.push_back('S');
    v2.push_back('F');
    v2.push_back('C');
    v2.push_back('S');
    v3.push_back('A');
    v3.push_back('D');
    v3.push_back('E');
    v3.push_back('E');
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
//    std::vector<std::vector<char>> v;
//    std::vector<char> v1;
//    std::vector<char> v2;
//    std::vector<char> v3;
//    v1.push_back('A');
//    v1.push_back('A');
//    v1.push_back('A');
//    v1.push_back('A');
//    v2.push_back('A');
//    v2.push_back('A');
//    v2.push_back('A');
//    v2.push_back('A');
//    v3.push_back('A');
//    v3.push_back('A');
//    v3.push_back('A');
//    v3.push_back('A');
//    v.push_back(v1);
//    v.push_back(v2);
//    v.push_back(v3);
    auto result= s.exist(v, "ABCCED");
    std::cout << result << std::endl;
}

