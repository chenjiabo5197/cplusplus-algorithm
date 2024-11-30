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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        // 用于保存索引为偶数的节点的头结点，最后让奇数节点的尾指针指向该头结点
        ListNode* evenHead = head->next;
        while (evenNode != nullptr && evenNode->next != nullptr)
        {
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;
            evenNode->next = oddNode->next;
            evenNode = evenNode->next;
        }
        // 从循环中出来后，有两种可能，evenNode为nullptr，链表总长度为奇数，evenNode->next为nullptr，料表总长度为偶数
        // 两种情况下，oddNode指向的节点都是最后一个奇节点，直接让其指向evenHead即可
        oddNode->next = evenHead;
        return head;
    }
};