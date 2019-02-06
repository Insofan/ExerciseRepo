//
// @ClassName offer06
// @Description TODO
// @Date 2019/2/6 9:50 PM
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
   void printList(ListNode *head) {

       while  (head) {
           cout << head->val << " ";
           head = head->next;
       }

       cout << endl;
   }

   ListNode *reverse(ListNode *head) {

       ListNode *newHead = NULL;

       while (head) {
           ListNode *next = head->next;
           head->next = newHead;
           newHead = head;
           head = next;
       }

       return newHead;
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


    Solution sol;

    sol.printList(&a1);

    ListNode *rever = sol.reverse(&a1);

    sol.printList(rever);


    return 0;
}
