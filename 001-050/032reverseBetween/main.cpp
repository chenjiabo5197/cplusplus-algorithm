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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* preNode = newHead;
        ListNode* currNode = head;
        for (int i = 1; i < left; ++i) {
            currNode = currNode->next;
            preNode = preNode->next;
        }
        // 此时currNode指向要开始反转的节点，preNode指向上一个节点,后preNode保持不变，因为要将反转区间与未翻转的区间连起来
        for (int i = left; i < right; ++i) {
            ListNode* tempNode = currNode->next;
            currNode->next = tempNode->next;
            tempNode->next = preNode->next;
            preNode->next = tempNode;
        }
        return newHead->next;
    }
};