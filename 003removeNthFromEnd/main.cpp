/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> node_vector;
        auto temp_node = head;
        while (temp_node != nullptr)
        {
            node_vector.push_back(temp_node);
            temp_node = temp_node->next;
        }
        int vector_length = node_vector.size();
        if(vector_length == n)
        {
            return head->next;
        }
        // 要删除的元素是length-1-(n-1)即为length-n
        node_vector[vector_length-n-1]->next = node_vector[vector_length-n]->next;
        return head;
    }
};