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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* frontNode = head;
        ListNode* behindNode = nullptr;
        while (frontNode != nullptr)
        {
            frontNode = frontNode->next;
            if (behindNode != nullptr)
            {
                behindNode = behindNode->next;
            }
            n--;
            if(n == 0)
            {
                behindNode = newHead;
            }
        }
        // 因为n最小为1，所以此处behindNode离尾节点最少还有一个节点，behindNode->next不为null
        behindNode->next = behindNode->next->next;
        return newHead->next;
    }
};