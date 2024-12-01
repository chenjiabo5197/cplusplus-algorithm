#include <iostream>
#include <vector>

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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> left_node;
        vector<TreeNode*> right_node;
        left_node = helper(root->left, left_node, -1);
        right_node = helper(root->right, right_node, 1);
        if(left_node.size() != right_node.size()){
            return false;
        }
        for (int i = 0; i < left_node.size(); ++i) {
            if (left_node[i] == nullptr && right_node[i] == nullptr)
            {
                continue;
            }
            if((left_node[i] == nullptr && right_node[i] != nullptr) || (right_node[i] == nullptr && left_node[i] != nullptr) || (left_node[i]->val != right_node[i]->val))
            {
                return false;
            }
        }
        return true;
    }

    vector<TreeNode*> helper(TreeNode* root, vector<TreeNode*> node_vector, int direction)
    {
        node_vector.push_back(root);
        if (root == nullptr)
        {
            return node_vector;
        }
        if(direction == -1)
        {
            node_vector = helper(root->left, node_vector, -1);
            node_vector = helper(root->right, node_vector, -1);
        }
        else
        {
            node_vector = helper(root->right, node_vector, 1);
            node_vector = helper(root->left, node_vector, 1);
        }
        return node_vector;
    }
};