//
// @ClassName offer240209
// @Description TODO
// @Date 2019/2/9 10:00 PM
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

    ListNode * reverseList(ListNode * head) {
        ListNode *res = NULL;

        while (head) {
            ListNode *next = head->next;
            head->next = res;
            res = head;
            head = next;
        }

        return res;
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
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    printList(&a1);
    Solution sol;

    ListNode *res = sol.reverseList(&a1);
    printList(res);
    return 0;
}
