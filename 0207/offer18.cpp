//
// @ClassName offer18
// @Description TODO
// @Date 2019/2/7 4:44 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution {
public:
    ListNode * deleteNode(ListNode *head, ListNode *node) {
        ListNode *newHead = NULL;
        newHead->next = head;
        while (head) {
            if (head->next && head->next == node) {
                head =head->next->next;
            } else {
                head= head->next;
            }
        }

        return newHead->next;
    }
};


void printList(ListNode *head) {
    while (head) {
        cout << head->val <<" ";
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

  ListNode *res =  sol.deleteNode(&a1, &a1);
    printList(res);



    return 0;
}
