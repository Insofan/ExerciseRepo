// 
// @ClassName Tree0226
// @Description TODO
// @Date 19-2-26 下午9:14
// @Created by Insomnia
//

#include <iostream>
#include <stack>

struct BSTree{
    int val;
    BSTree *left;
    BSTree *right;

    BSTree(int x): val(x), left(NULL), right(NULL){};
};


using namespace std;
class Solution {
public:
    void preOrder(BSTree *root) {

        if (!root) {
            return;
        }

        stack<BSTree *> s;

        BSTree *p = root;
        while (!s.empty() || p) {
            while (p) {
               cout << p->val << " ";
               s.push(p);
               p = p->left;
            }

            p = s.top();
            s.pop();
            p = p->right;
        }
    }

    void inOrder(BSTree *root) {

        if (!root) {
            return;
        }

        stack<BSTree *> s;

        BSTree *p = root;
        while (!s.empty() || p) {
            while (p) {
               s.push(p);
               p = p->left;
            }

            p = s.top();
            cout << p->val << " ";
            s.pop();
            p = p->right;
        }
    }

    void postOrder(BSTree *root) {
        if (!root) {
            return;
        }

        stack<BSTree *> s;
        BSTree *p = root;
        BSTree *last = NULL;

        while (!s.empty() || p) {
            if (p->left) {
                s.push(p);
                p = p->left;
            } else {
                BSTree *tmp = s.top();
            }
        }
    }
};


class Solution2 {
public:
    void postOrder(BSTree *root) {
        if (!root) {
            return;
        }

        stack<BSTree *> s;
        BSTree *p = root;

        BSTree *last = NULL;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            } else  {
                BSTree *top = s.top();
                if (top->right && top->right != last) {
                    p = top->right;
                } else {
                    s.pop();
                    last = top;
                    cout << top->val << " ";
                }
            }
        }
    }
};

int main() {
    BSTree a1(10);
    BSTree a2(5);
    BSTree a3(12);
    BSTree a4(4);
    BSTree a5(7);

    a1.left = &a2;
    a1.right = &a3;

    a2.left = &a4;
    a2.right = &a5;

    Solution sol;

    sol.inOrder(&a1);

    return 0;
}