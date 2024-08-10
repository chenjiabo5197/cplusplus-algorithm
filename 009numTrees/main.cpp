#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> result(n+1, 0);
        result[0] = 1;
        result[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <=i ; ++j) {
                /*
                 * 此处是笛卡尔积，原因是当以j为根节点构建搜索二叉树时，左子树的所有可能性是result[j-1]，右子树的所有可能性是
                 * result[i-j]，其中i表示所有节点的数量，故result[j-1]*result[i-j]为j为根节点的二叉搜索树种类数，然后i个节点
                 * 即将从1到i的所有可能性加起来
                 */
                result[i] += result[j-1] * result[i-j];
            }
        }
        return result[n];
    }
};

int main() {
    Solution s;
    auto result= s.numTrees(3);
    std::cout << result << std::endl;
}

