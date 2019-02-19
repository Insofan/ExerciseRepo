//
// @ClassName OrderBt0219
// @Description TODO
// @Date 2019/2/19 9:22 AM
// @Created by Insomnia
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

struct BinaryTree {
    int val;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int x): val(x), left(NULL), right(NULL){};
};

using namespace std;

class Solution1 {
public:
    void preOrder(BinaryTree *root) {
        if (!root) {
            return;
        }

        //pre
        //cout << root->val << " ";
        preOrder(root->left);
        //inorder
        cout << root->val << " ";
        preOrder(root->right);
        //postorder
//        cout << root->val << " ";
    }

    vector<vector<int> > layerOrder(BinaryTree *root) {
        vector<vector<int> > res;
        layerHelper(root, res, 0);
        return res;
    }

private:
    void layerHelper(BinaryTree *root, vector<vector<int> > &res, int layer) {
        if (!root) {
            return;
        }

        if (res.size() == layer) {
            res.push_back(vector<int>());
        }

        res[layer].push_back(root->val);
        layerHelper(root->left, res, layer + 1);
        layerHelper(root->right, res, layer + 1);

    }
};


class Solution2 {
public:
    void preOrder(BinaryTree *root) {
        stack<BinaryTree *> myStack;

        BinaryTree *cur = root;

        while  (!myStack.empty() || cur) {

            while (cur) {
                myStack.push(cur);
                cout << cur->val << " ";
                cur = cur->left;
            }


            cur = myStack.top();
            myStack.pop();
            cur = cur->right;
        }
    }

    void inOrder(BinaryTree *root) {
        stack<BinaryTree *> s;
        BinaryTree * p = root;
        while (!s.empty() || p) {

            while (p) {
                s.push(p);
                p = p->left;
            }

            p = s.top();
            s.pop();

            cout << p->val << " ";
            p = p->right;
        }
    }

    void postOrder(BinaryTree *root) {
        stack<BinaryTree *> s;
        BinaryTree          *p    = root;
        BinaryTree          *last = NULL;

        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                BinaryTree *top = s.top();
                if (top->right && last != top->right) {
                    p = top->right;
                } else {
                    cout << top->val << " ";
                    last = top;
                    s.pop();
                }
            }
       }
    }
};



int main() {
    BinaryTree a1(1);
    BinaryTree a2(2);
    BinaryTree a3(3);
    BinaryTree a4(4);
    BinaryTree a5(5);

    a1.left = &a2;
    a1.right = &a3;

    a2.left = &a4;
    a2.right = &a5;

    Solution1 sol1;

    sol1.preOrder(&a1);
    cout << endl;
    /*
    vector<vector<int> > res = sol1.layerOrder(&a1);
    for ( int i = 0; i < res.size(); i++) {
        for ( int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
     */

    Solution2 sol2;
//    sol2.preOrder(&a1);
//    sol2.inOrder(&a1);
    sol2.postOrder(&a1);

    return 0;
}
