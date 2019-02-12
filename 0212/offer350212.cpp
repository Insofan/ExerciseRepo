// 
// @ClassName offer350212
// @Description TODO
// @Date 19-2-12 下午4:33
// @Created by Insomnia
//

#include <iostream>
#include <map>
#include <vector>


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

using namespace std;

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        map<RandomListNode *, int> nodeMap;
        vector<RandomListNode *> nodeVec;
        RandomListNode *ptr = pHead;
        int idx = 0;
        while (ptr) {
            nodeMap[ptr] = idx++;
            nodeVec.push_back(new RandomListNode(ptr->label));
            ptr = ptr->next;
        }
        nodeVec.push_back(NULL);

        ptr = pHead;

        idx = 0;
        while (ptr) {
            nodeVec[idx]->next = nodeVec[idx+1];
            if (ptr->random) {
                int id = nodeMap[ptr->random];
                nodeVec[idx]->random = nodeVec[id];
            }
            ptr = ptr->next;
            idx++;
        }

        return nodeVec[0];
    }
};

int main() {

    RandomListNode a1(1);
    RandomListNode a2(2);
    RandomListNode a3(3);
    RandomListNode a4(4);
    RandomListNode a5(5);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;

    a1.random = &a3;
    a2.random = &a4;
    a3.random = &a5;
    a4.random = &a1;
    a5.random = NULL;

    Solution sol;

    RandomListNode *res = sol.Clone(&a1);


    return 0;
}
