//
// @ClassName offer250209
// @Description TODO
// @Date 2019/2/9 10:05 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution {
public:
    ListNode * mergeTwoList(ListNode *l1, ListNode *l2) {

//        ListNode *preHead =  new ListNode(-1);
//        ListNode *cur = preHead;
        ListNode tmp(0);
        ListNode *cur = &tmp;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur ->next;
        }

        if (l1) {
            cur->next = l1;
//            l1 = l1->next;
//            cur = cur ->next;
        }

        if (l2) {
            cur->next = l2;
//            l2 = l2->next;
//            cur = cur ->next;
        }

        return tmp.next;
    }

    ListNode *kthListMerge(vector<ListNode *> listVec) {
        if (listVec.empty()) {
            return NULL;
        }
        while (listVec.size() > 1) {
            listVec.push_back(mergeTwoList(listVec[0], listVec[1]));
            listVec.erase(listVec.begin());
            listVec.erase(listVec.begin());
        }

        return listVec.front();
    }
};


void printList(ListNode *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    ListNode a1(1);
    ListNode a2(3);
    ListNode a3(5);
    ListNode a4(7);
    ListNode a5(9);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    ListNode b1(2);
    ListNode b2(4);
    ListNode b3(6);
    ListNode b4(8);
    ListNode b5(10);

    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;

    ListNode c1(11);
    ListNode c2(13);
    ListNode c3(15);
    ListNode c4(17);
    ListNode c5(19);

    c1.next = &c2;
    c2.next = &c3;
    c3.next = &c4;
    c4.next = &c5;

    ListNode d1(12);
    ListNode d2(14);
    ListNode d3(16);
    ListNode d4(18);
    ListNode d5(20);

    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d4;
    d4.next = &d5;
    vector<ListNode *> listVec;
    listVec.push_back(&a1);
    listVec.push_back(&b1);
    listVec.push_back(&c1);
    listVec.push_back(&d1);

    Solution sol;
//    ListNode *res = sol.mergeTwoList(&a1, &b1);
//    printList(res);

    ListNode *res2 = sol.kthListMerge(listVec);
    printList(res2);

    return 0;
}
