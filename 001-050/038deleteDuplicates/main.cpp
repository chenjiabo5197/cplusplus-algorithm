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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* preNode = head;
        ListNode* curNode = head->next;
        while (curNode != nullptr)
        {
            if(curNode->val == preNode->val)
            {
                preNode->next = curNode->next;
            }
            else
            {
                preNode = preNode->next;
            }
            curNode = curNode->next;
        }
        return head;
    }
};