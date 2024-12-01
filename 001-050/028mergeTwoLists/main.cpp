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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if(list1 == nullptr && list2 == nullptr)
//        {
//            return nullptr;
//        }
//        else if(list1 == nullptr)
//        {
//            return list2;
//        }
//        else if(list2 == nullptr)
//        {
//            return list1;
//        }
//        ListNode* newHead = new ListNode();
//        if(list1->val > list2->val)
//        {
//            newHead->next = list2;
//            list2->next = mergeTwoLists(list1, list2->next);
//        }
//        else
//        {
//            newHead->next = list1;
//            list1->next = mergeTwoLists(list1->next, list2);
//        }
//        return newHead->next;
        ListNode* newHead = new ListNode();
        ListNode* preNode = newHead;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val > list2->val)
            {
                preNode->next = list2;
                list2 = list2->next;
                preNode = preNode->next;
            }
            else
            {
                preNode->next = list1;
                list1 = list1->next;
                preNode = preNode->next;
            }
        }
        if(list1 != nullptr)
        {
            preNode->next = list1;
        }
        if (list2 != nullptr)
        {
            preNode->next = list2;
        }
        return newHead->next;
    }
};