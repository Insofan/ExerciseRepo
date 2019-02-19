//
// @ClassName DeleteNode
// @Description TODO
// @Date 2019/2/19 3:34 PM
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

class Soltuion  {
public:
    ListNode * deleteNode(ListNode *head, int val) {
        ListNode preHead = ListNode(0);
        preHead.next = head;
        ListNode *cur = &preHead;

        while (cur) {
            if (cur->next && cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return preHead.next;
    }

};
void printList(ListNode *head) {
    while (head) {
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
    Soltuion sol;
    ListNode *res = sol.deleteNode(&a1, 1);
    printList(res);



    return 0;
}
