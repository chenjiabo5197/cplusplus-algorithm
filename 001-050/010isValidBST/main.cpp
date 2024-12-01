#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecurion(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTRecurion(TreeNode* root, long long min_value, long long max_value)
    {
        if(root == nullptr)
        {
            return true;
        }
        if (root->val <= min_value || root->val >= max_value)
        {
            return false;
        }
        return isValidBSTRecurion(root->left, min_value, root->val) && isValidBSTRecurion(root->right, root->val, max_value);
    }
};

int main() {
//    Solution s;
//    TreeNode n3(3);
//    TreeNode n7(7);
//    TreeNode n6(6, &n3, &n7);
//    TreeNode n4(4);
//    TreeNode n5(5, &n4, &n6);
    Solution s;
    TreeNode n3(3);
    TreeNode n1(1);
    TreeNode n2(2, &n1, &n3);
//    Solution s;
//    TreeNode n56(56);
//    TreeNode n47(47, nullptr, &n56);
//    TreeNode n27(27);
//    TreeNode n19(19, nullptr, &n27);
//    TreeNode n26(26, &n19, nullptr);
//    TreeNode n32(32, &n26, &n47);

    auto result= s.isValidBST(&n2);
    std::cout << result << std::endl;
}

