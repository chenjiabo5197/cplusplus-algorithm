#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* resultNext = result;
        int tempSum = 0;
        int carry = 0;  // 进位
        while (l1 != nullptr && l2 != nullptr)
        {
            tempSum = l1->val + l2->val + carry;
            carry = tempSum / 10;
            ListNode* temp = new ListNode(-1);
            if(tempSum >= 10)
            {
                temp->val = tempSum % 10;
            }
            else
            {
                temp->val = tempSum;
            }
            resultNext->next = temp;
            resultNext = resultNext->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            tempSum = l1->val + carry;
            carry = tempSum / 10;
            ListNode* temp = new ListNode(-1);
            if(tempSum >= 10)
            {
                temp->val = tempSum % 10;
            }
            else
            {
                temp->val = tempSum;
            }
            resultNext->next = temp;
            resultNext = resultNext->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            tempSum = l2->val + carry;
            carry = tempSum / 10;
            ListNode* temp = new ListNode(-1);
            if(tempSum >= 10)
            {
                temp->val = tempSum % 10;
            }
            else
            {
                temp->val = tempSum;
            }
            resultNext->next = temp;
            resultNext = resultNext->next;
            l2 = l2->next;
        }
        // 需要进位，额外创建一个节点
        if(carry != 0)
        {
            ListNode* temp = new ListNode(carry);
            resultNext->next = temp;
        }
        return result->next;
    }
};

int main()
{
    Solution sl;
    ListNode l19(9);

    ListNode l219(9);
    ListNode l229(9, &l219);
    ListNode l239(9, &l229);
    ListNode l249(9, &l239);

    auto result = sl.addTwoNumbers(&l19, &l249);
    while (result != nullptr)
    {
        std::cout << result->val << std::endl;
        result =result->next;
    }

    return 0;
}

