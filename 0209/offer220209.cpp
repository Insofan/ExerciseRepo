//
// @ClassName offer220209
// @Description TODO
// @Date 2019/2/9 9:49 PM
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
    ListNode *kThListNode(ListNode *head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (k) {
            fast = fast->next;
            k--;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
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
    ListNode *res =  sol.kThListNode(&a1, 2);
    cout << res->val << endl;

    return 0;
}
