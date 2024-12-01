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
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        // 当前正在访问的节点，一般判断当前正在访问的节点的下一个节点的值和当前节点的下一个节点的下一个节点的值是否相等
        ListNode* curNode = newHead;
        // 此处必须判断curNode->next->next != nullptr，因为下面if判断里取curNode->next->next->val，若不判断易造成空指针
        while (curNode->next != nullptr && curNode->next->next != nullptr)
        {
            if (curNode->next->val == curNode->next->next->val)
            {
                // 储存要删除的节点的值
                int temp = curNode->next->val;
                // 当前节点的下一个节点的值与要删除的节点值相等
                while (curNode->next != nullptr && curNode->next->val == temp)
                {
                    // 删除当前节点的下一个节点
                    curNode->next = curNode->next->next;
                }
                //从while循环出来后当前节点的下一个节点的值与要删除的节点值不同，则循环将要删除的节点删除完了
            }
            else
            {
                curNode = curNode->next;
            }
        }
        return newHead->next;
    }
};