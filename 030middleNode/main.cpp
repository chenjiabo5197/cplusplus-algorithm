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
    ListNode* middleNode(ListNode* head) {
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        while (fastNode != nullptr && fastNode->next != nullptr)
        {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
        }
        // 链表长度为奇数，则此时fastNode->next指向nullptr,slowNode指向中间节点；
        // 若为偶数，此时fastNode为nullptr，slowNode指向中间节点的后面节点
        return slowNode;
    }
};