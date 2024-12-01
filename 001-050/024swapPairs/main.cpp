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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* subHead = swapPairs(head->next->next);
        ListNode* nextNode = head->next;
        nextNode->next = head;
        head->next = subHead;
        return nextNode;
    }
};