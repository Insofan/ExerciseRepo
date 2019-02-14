// 
// @ClassName offer520214
// @Description TODO
// @Date 19-2-14 下午9:54
// @Created by Insomnia
//

#include <iostream>
#include <vector>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};
using namespace std;

class Solution {
public:
    ListNode * commonListNode(ListNode *l1, ListNode *l2) {

        map<ListNode *, int> hashMap;

        while (l1) {
            hashMap[l1]++;
            l1 = l1->next;
        }

        while (l2) {
            if (hashMap[l2] > 0) {
                return l2;
            }

            l2 = l2->next;
        }

        return NULL;
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

    ListNode b1(11);
    ListNode b2(12);
    ListNode b3(13);

    b1.next = &b2;
    b2.next = &b3;
    b3.next = &a4;

    //printList(&b1);

    Solution sol;

    cout << sol.commonListNode(&a1, &b1)->val << endl;

    return 0;
}