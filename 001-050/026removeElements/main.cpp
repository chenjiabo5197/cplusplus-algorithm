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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
        {
            return head;
        }
        ListNode newHead(-1, nullptr);
        newHead.next = head;
        ListNode* frontNode = head;
        ListNode* behindNode = &newHead;
        while (frontNode != nullptr)
        {
            if(frontNode->val == val)
            {
                behindNode->next = frontNode->next;
                frontNode = frontNode->next;
            }
            else
            {
                frontNode = frontNode->next;
                behindNode = behindNode->next;
            }
        }
        return newHead.next;
    }
};