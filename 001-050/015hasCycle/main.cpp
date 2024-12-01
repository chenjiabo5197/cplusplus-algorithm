#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        auto fastNode = head;
        auto slowNode = head;
        while (fastNode != nullptr && fastNode->next != nullptr && slowNode != nullptr)
        {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode)
            {
                break;
            }
        }
        if(fastNode != slowNode){
            return false;
        }
        return true;
    }
};