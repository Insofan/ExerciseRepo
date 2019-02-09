//
// @ClassName offer230209
// @Description TODO
// @Date 2019/2/9 9:54 PM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};
using namespace std;

class Solution {
public:
   ListNode * circleList(ListNode  *head) {
       ListNode *fast = head;
       ListNode *slow = head;
       ListNode *meet = NULL;


       while (fast) {
           fast = fast->next;
           if (!fast) {
               return nullptr;
           }
           fast = fast->next;
           slow = slow->next;
           if (fast == slow) {
               meet = fast;
               break;
           }
       }


       while (head && meet) {
           head = head->next;
           meet = meet->next;
           if (head == meet) {
               return meet;
           }
       }

       return nullptr;
   }
};


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
    a5.next = &a2;

    Solution sol;

    ListNode *res = sol.circleList(&a1);

    cout << res->val << endl;


    return 0;
}
