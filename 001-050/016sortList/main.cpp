#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        std::sort(v.begin(), v.end());
        temp = head;
        for (int i = 0; i < v.size(); ++i, temp=temp->next) {
            temp->val = v[i];
        }
        return head;
    }
    // 会超时
//    ListNode* sortList(ListNode* head) {
//        if(head == nullptr)
//        {
//            return head;
//        }
//        map<int, ListNode*> m;
//        while (head != nullptr)
//        {
//            ListNode* temp = new ListNode();
//            auto it = m.find(head->val);
//            temp->val = head->val;
//            if (it != m.end())
//            {
//                while (it->second->next != nullptr)
//                {
//                    it->second = it->second;
//                }
//                it->second->next = temp;
//            }
//            m.insert(make_pair(temp->val, temp));
//            head = head->next;
//        }
//        ListNode* temp = new ListNode();
//        temp = new ListNode();
//        for(auto myPair: m)
//        {
//            temp->next = myPair.second;
//            while (myPair.second->next != nullptr)
//            {
//                myPair.second = myPair.second->next;
//                temp = temp->next;
//            }
//            temp = temp->next;
//        }
//        return m.begin()->second;
//    }
};

int main() {
    Solution s;
    ListNode l0(0);
    ListNode l4(4, &l0);
    ListNode l44(4, &l4);
    ListNode l3(3, &l44);
    ListNode l5(5, &l3);
    ListNode l1(-1, &l5);

    auto result= s.sortList(&l1);
    while (result != nullptr)
    {
        std::cout << result->val << std::endl;
        result = result->next;
    }
}

